#include "main.h"
/**
 * remove_comment - removes comments from the input
 * @str: input string
 * Return: input string without strings
 */
char *remove_comment(char *str)
{
int i, new;

new = 0;
for (i = 0; str[i]; i++)
{
if (str[i] == '#')
{
if (i == 0)
{
return (NULL);
}
if (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == ';')
new = i;
}
}
if (new != 0)
{
str = _realloc(str, i, new + 1);
str[new] = '\0';
}
return (str);
}
