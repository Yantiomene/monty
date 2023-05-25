#include "monty.h"

/**
 * _add - devides the second top element of the stack by the top element
 * @head: pointer to the pointer to the head of the stack
 * @line: current line number
 *
 * Return: nothing
 */
void _add(stack_t **head, unsigned int line)
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
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n += (*head)->n;
	pop(head, line);
}
