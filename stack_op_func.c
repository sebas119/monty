#include "monty.h"

int data;

void pushStack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("PUSH STACK FUNCTION\n");
	printf("-- %d --\n", data);
}

void printStack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	printf("PALL FUNCTION\n");
}
