#include "monty.h"

/**
 * _sub - computes the rest of the division of 2nd element by the 1st element
 * @head: pointer to the pointer to the head of the stack
 * @line: current line number
 *
 * Return: nothing
 */
void _sub(stack_t **head, unsigned int line)
{
	stack_t *tmp;
	unsigned int count = 0;

	tmp = *head;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n -= (*head)->n;
	pop(head, line);
}
