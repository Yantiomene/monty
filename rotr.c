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
	stack_t *top, *temp;

	(void)line;

	if (*head && (*head)->next)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;

		top = temp;
		top->prev = NULL;
		top->next = *head;
		(*head)->prev = top;
		*head = top;
	}
}
