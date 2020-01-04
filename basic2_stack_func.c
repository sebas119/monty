#include "monty.h"

/**
 * addStack - Free the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void addStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	top = (*stack)->n;
	free(*stack);
	*stack = temp;
	(*stack)->n = (*stack)->n + top;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * subStack - Free the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void subStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	top = (*stack)->n;
	free(*stack);
	*stack = temp;
	(*stack)->n = (*stack)->n - top;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * divStack - Free the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void divStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	top = (*stack)->n;
	if (top == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	free(*stack);
	*stack = temp;
	(*stack)->n = (*stack)->n / top;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * mulStack - Free the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void mulStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	top = (*stack)->n;
	free(*stack);
	*stack = temp;
	(*stack)->n = (*stack)->n * top;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * modStack - Free the stack
 * @stack: Head of the list
 * @line_number: Head of the list
 *
 * Return: nothing
 */
void modStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	top = (*stack)->n;
	if (top == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	free(*stack);
	*stack = temp;
	(*stack)->n = (*stack)->n % top;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}
