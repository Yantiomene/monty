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
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n += (*head)->n;
	pop(head, line);
}
