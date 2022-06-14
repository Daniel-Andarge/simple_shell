#include "main.h"
/**
 * storeinput - stores the string passed to the
 * string
 * @str: pointer to passed string
 * Return: 0 on success and 1 on failure
 */
int storeinput(char *str)
{
char *buf;
int x, i;
size_t length = 1000;

buf = malloc(length * sizeof(char));
if (buf == NULL)
	return (1);
x = _getline(&buf, &length, stdin);

if (x != -1)
{
for (i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == 10)
	buf[i] = '\0';
}
_strcpy(str, buf);
free(buf);
return (0);
}
else
return (1);
}
