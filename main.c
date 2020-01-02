#include "monty.h"

/**
 * main -
 * @argc:
 * @argv:
 * Return:
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
 * montyFile -
 * @argc:
 * @argv:
 * Return:
 */
void montyFile(char **argv)
{
	const char *filename = argv[1];
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		montyInit(line, line_number);
		line_number++;
	}

	fclose(fp);

	if (line != NULL)
		free(line);
}

/**
 * montyInit -
 * @argc:
 * @argv:
 * Return:
 */
void montyInit(char *line, unsigned int line_number)
{
	void (*op_func)(stack_t * *stack, unsigned int line_number);
	const char *s = " \t\n";
	char *token;
	stack_t *top = NULL;

	token = strtok(line, s);
	while (token != NULL)
	{
		op_func = getOpcode(token);
		token = strtok(NULL, s);
		if (token != NULL)
			data = atoi(token);
		if (op_func != NULL)
			op_func(&top, line_number);
	}
}
