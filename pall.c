#include "monty.h"

/**
 * pall - prints all data of a stack
 * @head: pointer to pointer to the head of the stackk
 * @line: curent line number
 *
 * Return: nothing
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *last;

	(void)line;
	last = *head;
	while (last)
	{
		printf("%d\n", last->n);
		last = last->next;
	}
}
