#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: pointer to to the pointer to the head of the stack
 * @line: current line number
 *
 * Return: nothing
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *last;

	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	last = *head;
	*head = (*head)->next;
	free(last);
}
