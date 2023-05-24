#include "monty.h"

/**
 * add_dnodeint - add a new node at the top of a stack
 * @head: pointer to the stack
 * @n: data to be inserted
 *
 * Return: a pointer to a stack or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *top;

	if (head == NULL)
		return (NULL);
	top = malloc(sizeof(stack_t));
	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	top->n = n;
	top->next = *head;
	if (*head)
		(*head)->prev = top;
	top->prev = NULL;
	*head = top;
	return (*head);
}

/**
 * add_dnodeint_end - add a new node at the end of a stack
 * @head: pointer to the pointer of the head of the stack
 * @n: data to be inserted
 *
 * Return: a pointer to the stack or NULL if failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *end, *last;

	if (head == NULL)
		return (NULL);
	end = malloc(sizeof(stack_t));
	if (!end)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	end->n = n;
	end->next = NULL;
	if (*head == NULL)
	{
		end->prev = NULL;
		*head = end;
		return (*head);
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = end;
	end->prev = last;
	return (end);
}

/**
 * free_dlistint - free a stack
 * @head: pointer to a node
 *
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *last;

	while ((last = head) != NULL)
	{
		head = head->next;
		free(last);
	}
}
