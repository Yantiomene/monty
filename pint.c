#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @head: pointer to the pointer to the head of the stack
 * @line: current line number
 *
 */
void pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
