#include "monty.h"

/**
 * get_func - get the function associated to an instruction
 * @op: instruction
 *
 * Return: pointer to the funciton associated or NULL if not found
 */
void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i;

	for (i = 0; operations[i].opcode; i++)
	{
		if (strcmp(operations[i].opcode, op) == 0)
			break;
	}
	return (operations[i].f);
}