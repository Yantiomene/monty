#include  "monty.h"

data_t gvar;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t size = 256;
	ssize_t num_read = 0;
	void (*f)(stack_t **stack, unsigned int line_number);
	char *token = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	init_var(fd);
	num_read = _getline(&gvar.buf, &size, fd);
	while (num_read != -1)
	{
		token = strtok(gvar.buf, " \t\n");
		if (token && token[0] != '#')
		{
			f = get_func(token);
			if (!f)
			{
			fprintf(stderr, "L%u: ", gvar.line);
			fprintf(stderr, "unknown instruction %s\n", token);
			free_var();
			exit(EXIT_FAILURE);
			}
			gvar.arg = strtok(NULL, " \t\n");
			f(&gvar.head, gvar.line);
		}
		num_read = _getline(&gvar.buf, &size, fd);
		gvar.line++;
	}
	free_var();
	return (0);
}
