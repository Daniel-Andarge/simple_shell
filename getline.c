#include "main.h"
/**
 * put_line - puts the line in the buffer from
 * _getline
 * @lineptr: where string is stored
 * @buf: string gotten from getline
 * @n: initial size of buf
 * @j: confirmed size of buf
 */
void put_line(char **lineptr, size_t *n, char *buf, size_t j)
{
if (*lineptr == NULL)
{
if (j > BUFFER)
	*n = j;
else
	*n = BUFFER;
*lineptr = buf;
}
else if (*n < j)
{
if (j > BUFFER)
	*n = j;
else
	*n = BUFFER;
*lineptr = buf;
}
else
{
_strcpy(*lineptr, buf);
free(buf);
}
}
/**
 * _getline - gets a line from stdin
 * @lineptr: where the line is stored
 * @n: size of bytes
 * @stream: where it reads from
 * Return: no. of characters read or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
int i;
static ssize_t input;
ssize_t retval;
char *buf;
char store = 's';

if (input == 0)
	fflush(stream);
else
	return (-1);
input = 0;
buf = malloc(sizeof(char) * BUFFER);
if (buf == NULL)
	return (-1);
while (store != '\n')
{
i = read(STDIN_FILENO, &store, 1);
if (i == -1 || (i == 0 && input == 0))
{
free(buf);
return (-1);
}
if (i == 0 && input != 0)
{
input++;
break;
}
if (input >= BUFFER)
	buf = _realloc(buf, input, input + 1);
	buf[input] = store;
	input++;
}
buf[input] = '\0';
put_line(lineptr, n, buf, input);
retval = input;
if (i != 0)
	input = 0;
	return (retval);
}
