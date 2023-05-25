#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @head: pointer to the pointer of the head of the stack
 * @line: the current line number
 *
 * Return: nothing
 */
void pchar(stack_t **head, unsigned int line)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
