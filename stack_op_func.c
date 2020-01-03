#include "monty.h"

int data;

void pushStack(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	(void)line_number;

	if (new == NULL)
		return;

	new->n = data;
	new->prev = NULL;
	new->next = NULL;

	printf("VALUES OF *stack %p\n", (void *)*stack);

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
		printf("ENTRO AQUI\n");
	}

	*stack = new;
	printf("AFTER POINTER MEMORY *stack %p\n", (void *)*stack);
	printf("PUSH STACK FUNCTION\n");
	printf("-- %d --\n", data);
}

void printStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		return;
	(void)line_number;
	printf("PALL FUNCTION\n");
	printf("%d\n", (*stack)->n);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
