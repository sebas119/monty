#include "monty.h"

/**
 * *getOpcode - a
 * @token: a
 * Return: Function pointer
 */
void (*getOpcode(char *token))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t opcodes[] = {
		{"push", pushStack},
		{"pall", printStack},
		{"pint", topStack},
		{"pop", popStack},
		{"swap", swapStack},
		{"add", addStack},
		{"sub", subStack},
		{"div", divStack},
		{"mul", mulStack},
		{"mod", modStack},
		{"pchar", pcharStack},
		{"pstr", pstrStack},
		{"rotl", rotlStack},
		{NULL, NULL}};

	for (i = 0; opcodes[i].opcode != NULL; i++)
		if (strcmp(token, opcodes[i].opcode) == 0)
			return (opcodes[i].f);

	return (opcodes[i].f);
}
