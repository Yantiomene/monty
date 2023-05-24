#include "monty.h"

/**
 * swap - swaps the top 2 elements of the stack
 * @head: pointer to the pointer to the head of the stack
 * @line: current line number
 *
 * Return: nothing
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *last;
	unsigned int count = 0;

	last = *head;
	while (last)
	{
		count++;
		last = last->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	last = *head;
	*head = (*head)->next;
	last->next = (*head)->next;
	last->prev = (*head);
	(*head)->next = last;
	(*head)->prev = NULL;
}
