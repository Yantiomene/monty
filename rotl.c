#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @head: pointer to the pointer to the head of the stack
 * @line: current line number
 *
 * Return: nothing
 */
void rotl(stack_t **head, unsigned int line)
{
	stack_t *last, *second;

	(void)line;

	if (*head && (*head)->next)
	{
		last = *head;
		while (last->next)
			last = last->next;

		second = (*head)->next;
		second->prev = NULL;
		last->next = *head;
		(*head)->prev = last;
		(*head)->next = NULL;
		*head = second;
	}
}
