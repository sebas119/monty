#include "monty.h"

/**
 * main - Main function that loads a monty file
 * @argc: Number of arguments - Pointer to integer
 * @argv: Array of arguments
 * Return: 0 on success or 1 on failure
 */
int main(int argc, char **argv)
{
	(void)data;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	montyFile(argv);
	return (0);
}

/**
 * montyFile - Init the the tokenization of the data in monty file
 * @argv: Array of arguments
 * Return: nothing
 */
void montyFile(char **argv)
{
	const char *filename = argv[1];
	FILE *fp;
	char *buffer = NULL, **tokens = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&buffer, &len, fp)) != -1)
	{
		montyTokens(&buffer, &tokens, read);
		if (tokens != NULL)
			montyInit(&stack, &tokens, line_number);
		freeTokens(&tokens);
		line_number++;
	}

	fclose(fp);

	if (buffer != NULL)
		free(buffer);
	freeStack(stack);
}

/**
 * montyInit - Loads the data in the stack
 * @stack: Stack data structure
 * @tokens: Array of arrays with tokens
 * @line_number: Line number in the file - Integer
 * Return: a
 */
void montyInit(stack_t **stack, char ***tokens, unsigned int line_number)
{
	void (*op_func)(stack_t **stack, unsigned int line_number);

	unsigned int i;

	if ((strcmp((*tokens)[0], "nop") == 0) || (*((*tokens)[0]) == '#'))
		return;

	if (strcmp((*tokens)[0], "push") == 0)
	{
		for (i = 0; (*tokens)[i] != NULL; i++)
		{
			if (i == 1)
			{
				isNumber((*tokens)[i], line_number);
			}
		}
		if (i == 1 && (*tokens)[i] == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	op_func = getOpcode((*tokens)[0]);

	if (op_func != NULL)
		op_func(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, (*tokens)[0]);
		exit(EXIT_FAILURE);
	}

}

/**
 * isCharDigit - Check if the Char is a digit
 * @c: Character to check - char
 * Return: 1 if it's a digit or 0 if not
 */
int isCharDigit(int c)
{
	if ((c >= '0' && c <= '9') || (c == '-'))
		return (1);
	return (0);
}

/**
 * isNumber - Check if the check is a number
 * @pushData: Character to check - char
 * @line_number: Line number - unsigned int
 * Return: nothing
 */
void isNumber(char *pushData, unsigned int line_number)
{
	unsigned int i = 0;

	while (pushData[i] != '\0')
	{
		if (i == 0 && pushData[i] == '-')
			;
		else if (isCharDigit(pushData[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	data = atoi(pushData);
}

/**
 * freeTokens - Free memory of Tokens Linked List
 * @tokens: Pointer to a Linked list
 * Return: nothing
 */
void freeTokens(char ***tokens)
{
	if (*tokens != NULL)
	{
		free(*tokens);
		*tokens = NULL;
	}
}

/**
 * montyTokens - Read the buffer and get clean tokens
 * @buffer: Array of strings
 * @tokens: Pointer to array of strings
 * @read: Number of elements readed - ssize_t
 * Return: nothing
 */
void montyTokens(char **buffer, char ***tokens, ssize_t read)
{
	unsigned int countToken, i;

	if (read > 0)
	{
		i = 0;
		while ((*buffer)[i] == ' ' || (*buffer)[i] == '\t')
		{
			if ((*buffer)[i + 1] == '\n')
				return;
			i++;
		}
	}

	if (**buffer != '\n')
	{
		replaceNewLine(buffer);
		countToken = lenTokens(read, buffer);
		if (countToken > 3)
			countToken = 3;
		processTokens(tokens, buffer, countToken);
	}
}

/**
 * lenTokens - Get the number of words separated by a delimiter
 * @lenReaded: Len of the line readed
 * @buffer: Array of strings
 * Return: (unsigned int) of words in the buffer
 */
unsigned int lenTokens(ssize_t lenReaded, char **buffer)
{
	char *tempToken = NULL, *copyBuffer = NULL;
	int i;
	char *delim = " \n\t";

	copyBuffer = malloc(sizeof(char) * lenReaded);
	strcpy(copyBuffer, *buffer);
	tempToken = strtok(copyBuffer, delim);
	for (i = 0; tempToken != NULL; i++)
		tempToken = strtok(NULL, delim);
	i++; /* One more to save NULL */
	free(copyBuffer);
	return (i);
}

/**
 * replaceNewLine - Replace the new line in the buffer
 * by a null character
 * @buffer: Array of strings
 * Return: nothing
 */
void replaceNewLine(char **buffer)
{
	int i;

	for (i = 0; (*buffer)[i] != '\0'; i++)
		continue;
	(*buffer)[i - 1] = '\0'; /* Replace '\n' by '\0' */
}

/**
 * processTokens - Get all of the strings separated by a delimiter in
 * an array of strings
 * @tokens: Pointer to array of strings
 * @buffer: Array of strings
 * @countToken: number of tokens in the tokens variable
 *
 * Return: nothing
 */
void processTokens(char ***tokens, char **buffer, unsigned int countToken)
{
	char *token = NULL;
	unsigned int i;
	char *delim = " \n\t";

	token = strtok(*buffer, delim);

	if (strcmp(token, "push") == 0)
		countToken = 3;
	else
		countToken = 2;
	*tokens = malloc(sizeof(char *) * countToken);
	for (i = 0; token != NULL && i <= countToken - 2; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, delim);
	}
	(*tokens)[i] = NULL;
}


/**
 * freeStack - Free the stack
 * @stack: Head of the list
 *
 * Return: nothing
 */
void freeStack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		temp = stack;
		stack = temp->next;
		free(temp);
	}
}
