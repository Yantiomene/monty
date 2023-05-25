#include "monty.h"

/**
 * pstr - prints the string at the top of the stack
 * @head: pointer to the pointer of the head of the stack
 * @line: the current line number
 *
 * Return: nothing
 */
void pstr(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	(void)line;
	tmp = *head;
	while (tmp && (tmp->n > 0) && (tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
