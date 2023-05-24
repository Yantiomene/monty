#include "monty.h"

/**
 * init_var - initialize the global variable
 * @fd: file descriptor of the opened file
 *
 * Return: nothing
 */
void init_var(FILE *fd)
{
	gvar.line = 1;
	gvar.fd = fd;
	gvar.head = NULL;
	gvar.buf = NULL;
	gvar.arg = NULL;
}

/**
 * free_var - free the global variable
 *
 * Return: nothing
 */
void free_var(void)
{
	free_dlistint(gvar.head);
	free(gvar.buf);
	fclose(gvar.fd);
}
