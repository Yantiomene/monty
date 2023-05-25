#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - structure for the global variable
 * @line: current line  number
 * @fd: file descriptor of the opened file
 * @head: pointer to the head of the stack
 * @buf: buffer used to read the current line
 * @arg: argument of the instruction
 * @s_q: flag - 1 for stack and 0 for queue (default set to 1)
 *
 * Description: Global variable that will be shared on
 * source fileto hanlde instructions
 */
typedef struct data_s
{
	unsigned int line;
	FILE *fd;
	stack_t *head;
	char *buf;
	char *arg;
	int s_q;
} data_t;

extern data_t gvar;

/* gvar functions */
void init_var(FILE *fd);
void free_var(void);

/* dll functions */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* print_error */
void print_error(const char *msg, unsigned int  line);

/* get function */
void (*get_func(char *op))(stack_t **stack, unsigned int line_number);

/* _getline function */
ssize_t _getline(char **line, size_t *n, FILE *stream);

/* instructions functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);

#endif
