#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

extern int data;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

unsigned int lenTokens(ssize_t lenReaded, char **buffer);
void replaceNewLine(char **buffer);
void processTokens(char ***tokens, char **buffer, unsigned int countToken);
void freeTokens(char ***tokens);

void montyFile(char **argv);
void montyTokens(char **buffer, char ***tokens, ssize_t read);
void montyInit(stack_t **stack, char ***tokens, unsigned int line_number);

void freeStack(stack_t *stack);
/* Op Functions library */
void pushStack(stack_t **stack, unsigned int line_number);
void printStack(stack_t **stack, unsigned int line_number);
void topStack(stack_t **stack, unsigned int line_number);
void popStack(stack_t **stack, unsigned int line_number);
void swapStack(stack_t **stack, unsigned int line_number);
void addStack(stack_t **stack, unsigned int line_number);
void subStack(stack_t **stack, unsigned int line_number);
void divStack(stack_t **stack, unsigned int line_number);
void mulStack(stack_t **stack, unsigned int line_number);
void modStack(stack_t **stack, unsigned int line_number);
void pcharStack(stack_t **stack, unsigned int line_number);
void pstrStack(stack_t **stack, unsigned int line_number);
void rotlStack(stack_t **stack, unsigned int line_number);


void (*getOpcode(char *token))(stack_t **stack, unsigned int line_number);

int isCharDigit(int c);
void isNumber(char *pushData, unsigned int line_number);

#endif
