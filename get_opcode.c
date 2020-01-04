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
		{NULL, NULL}};

	for (i = 0; opcodes[i].opcode != NULL; i++)
		if (strcmp(token, opcodes[i].opcode) == 0)
			return (opcodes[i].f);

	return (opcodes[i].f);
}
