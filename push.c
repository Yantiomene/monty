#include "monty.h"

/**
 * push - pushez data to a stack
 * @head: pointer to the pointer the head of the stack
 * @line: current line number
 *
 */
void push(stack_t **head, unsigned int line)
{
	int n, i;

	if (!gvar.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		free_var();
		exit(EXIT_FAILURE);
	}
	for (i = 0; gvar.arg[i] != '\0'; i++)
	{
		if (!isdigit(gvar.arg[i]) && gvar.arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line);
			free_var();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(gvar.arg);
	if (gvar.s_q == 1)
		add_dnodeint(head, n);
	else if (gvar.s_q == 0)
		add_dnodeint_end(head, n);
}
