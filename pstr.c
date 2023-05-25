#include "monty.h"

/**
 * pstr - prints the string at the top of the stack
 * @head: pointer to the pointer of the head of the stack
 * @line: the current line number
 *
 * Return: nothing
 */
void pstr(stack_t **head, __attribute__ ((unused))unsigned int line)
{
	if (!head || !*head)
	{
		printf("\n");
		free_var();
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		free_var();
	}
	printf("%c\n", (*head)->n);
}
