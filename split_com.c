#include "main.h"
/**
 * is_delim - checks if character from string is a delimiter
 * @c: character from string
 * @delim: delimiter
 * Return: 1 if it's a delimeter and 0 if not
 */
unsigned int is_delim(char c, char *delim)
{
while (*delim != '\0')
{
if (c == *delim)
	return (1);
delim++;
}
return (0);
}
/**
 * _strtok - seperates a string using a delimiter
 * @str: string
 * @delim: delimiter
 * Return: a pointer to the seperated string
 */
char *_strtok(char *str, char *delim)
{
static char *hold;
char *ret;

if (!str)
	str = hold;
if (!str)
	return (NULL);
while (1)
{
if (is_delim(*str, delim))
{
str++;
continue;
}
if (*str == '\0')
return (NULL);
break;
}
ret = str;
while (1)
{
if (*str == '\0')
{
hold = str;
return (ret);
}
if (is_delim(*str, delim))
{
*str = '\0';
hold = str + 1;
return (ret);
}
str++;
}
}
/**
 * split_space - splits commands from arguments
 * @str: stored string from stdin
 * @par: array  of commands
 */
void split_space(char *str, char **par)
{
int i = 0;
char *piece;

piece = _strtok(str, " ");

for (i = 0; piece != NULL && i < MAXLIST; i++)
{
par[i] = piece;
piece = _strtok(NULL, " ");
}
par[i] = NULL;
}
