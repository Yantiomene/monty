#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @head: pointer to the pointer to the head of the stack
 * @line: current line number
 *
 * Return: nothing
 */

void rotr(stack_t **head, unsigned int line)
{
	stack_t *second, *temp, *last;

	(void)line;

	if (*head && (*head)->next)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;

		last = temp->prev;
		second = (*head)->next;
		last->next = *head;
		second->prev = temp;
		(last->next)->next = NULL;
		(last->next)->prev = last;
		*head = temp;
		(*head)->next = second;
		(*head)->prev = NULL;
	}
}
