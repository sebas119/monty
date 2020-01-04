#include "monty.h"

/**
 * pcharStack - Free the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void pcharStack(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}


/**
 * pstrStack - Prints the string starting at the top of the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void pstrStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	while (temp != NULL)
	{
		if (temp->n > 0 && temp->n < 128)
			printf("%c", temp->n);
		else
			break;
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotlStack - Prints the string starting at the top of the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void rotlStack(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack, *temp = *stack;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	if (temp->next != NULL)
		temp->next->prev = NULL;

	*stack = temp->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = top;
	top->prev = temp;
	top->next = NULL;
}
