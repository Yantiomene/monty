#include "monty.h"

/**
 * _realloc - reallocate memory
 * @ptr: pointer to the variable need more space in memory
 * @len: initial len
 * @new_len: new len
 *
 * Return: the pointer tot he new space allocated
 */
void *_realloc(void *ptr, size_t len, size_t new_len)
{
	void *new_ptr;

	if (!ptr)
		return (malloc(new_len));
	if (new_len == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_len == len)
		return (ptr);
	new_ptr = malloc(new_len);
	if (!new_ptr)
		return (NULL);
	if (new_len < len)
		memcpy(new_ptr, ptr, new_len);
	else
		memcpy(new_ptr, ptr, len);
	free(ptr);
	return (new_ptr);
}

/**
 * _getline - read a line from the stream
 * @line: pointer to the line
 * @n: pointer tot the size of the buffer pointed by the line
 * @stream: stream from which the line will be readed
 *
 * Return: the number of character readed or -1 if failed
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	char buf[256];

	if (line == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*line == NULL)
	{
		*n = sizeof(buf);
		*line = malloc(*n);
		if (!(*line))
			return (-1);
	}
	(*line)[0] = '\0';
	while (fgets(buf, sizeof(buf), stream) != NULL)
	{
		if (*n - strlen(*line) < sizeof(buf))
		{
			*n *= 2;
			*line = _realloc(*line, *n / 2, *n);
			if (!(*line))
			{
				free(line);
				return (-1);
			}
		}
		strcat(*line, buf);
		if ((*line)[strlen(*line) - 1] == '\n')
			return (strlen(*line));
	}
	return (-1);
}
