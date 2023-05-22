#include "main.h"

/**
 * get_line - function that reads input from the command line
 * @line_ptr: pointer to command line args
 * @n: size of command line args
 * Return: number of characters read
 */

ssize_t get_line(char **line_ptr, size_t *n)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos;
	static size_t buffer_size;
	size_t total_read = 0;
	ssize_t chars_read = 0;
	int newline_found = 0;

	if (*line_ptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*line_ptr = (char *)malloc(*n);
		if (*line_ptr == NULL) /* Memory allocation failed */
			return (-1);
	}

	while (1)
	{
		/* Refill the buffer if necessary */
		if (buffer_pos >= buffer_size)
		{
			if (refill_buffer(buffer, &buffer_pos, &buffer_size) <= 0)
			{
				if (total_read == 0) /* Error or end of file reached */
					return (-1);
				/* Return the line read before encountering the error or eof */
				break;
			}
		}

		/* Copy characters from the buffer to the line */
		newline_found = read_buffer(buffer, &buffer_pos,
				buffer_size, &total_read, line_ptr, n);
		if (newline_found)
			break;
	}

	(*line_ptr)[total_read] = '\0'; /* Null-terminate the line */
	chars_read = (ssize_t)total_read;
	return (chars_read);
}

/**
 * refill_buffer - function that refills the input buffer
 * @buffer: buffer to refill
 * @buffer_pos: current position in the buffer
 * @buffer_size: size of the buffer
 * Return: buffer_size
 */

ssize_t refill_buffer(char *buffer, size_t *buffer_pos, size_t *buffer_size)
{
	*buffer_pos = 0;
	*buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	return (*buffer_size);
}

/**
 * read_buffer - function that reads data from the input buffer
 * @buffer: buffer to read data from
 * @buffer_pos: current position in the buffer
 * @buffer_size: size of the buffer
 * @total_read: total characters read so far
 * @line_ptr: pointer to the line buffer
 * @n: size of the line buffer
 * Return: newline_found if newline is found
 */

int read_buffer(char *buffer, size_t *buffer_pos, size_t buffer_size,
		size_t *total_read, char **line_ptr, size_t *n)
{
	char *new_line_ptr = NULL;
	int newline_found = 0;

	while (*buffer_pos < buffer_size)
	{
		if (*total_read >= *n - 1)
		{
			/* Allocate a larger buffer and copy the contents */
			*n += BUFFER_SIZE;
			new_line_ptr = (char *)malloc(*n);
			if (new_line_ptr == NULL)
			{
				return (-1); /* Memory allocation failed */
			}
			_memcpy(new_line_ptr, *line_ptr, *total_read);
			free(*line_ptr);
			*line_ptr = new_line_ptr;
		}
		(*line_ptr)[(*total_read)++] = buffer[(*buffer_pos)++];
		if ((*line_ptr)[(*total_read) - 1] == '\n')
		{
			newline_found = 1;
			break; /* Return the line when encountering a newline character */
		}
	}
	return (newline_found);
}
