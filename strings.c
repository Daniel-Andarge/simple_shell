#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: char typr pointer
 * @s2: char type pointer
 * Return: difference in the values
 */
int _strcmp(char *s1, char *s2)
{
int i, m;

for (i = 0; s1[i] != '\0'; i++)
{
m = s1[i] - s2[i];
if (m != 0)
	break;
}
if (m == 0)
	m = s1[i] - s2[i];
	return (m);
}
/**
 * _strcpy - copies src to dest
 * @dest: char type pointer
 * @src: char type pointer
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
/**
 * _puts - prints a string followed by a new line to stdout
 * @str: char type pointer
 */
void _puts(char *str)
{
int i = 0;

for (i = 0; str[i] != '\0'; i++)
{
_putchar(str[i]);
}
_putchar(10);
}
/**
 * _strcat - concatenates two strings
 * @dest: char type pointer
 * @src: char type pointer
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
int i, j, k;

for (i = 0; dest[i] != '\0'; i++)
;
k = i;
for (i = k, j = 0; src[j] != '\0'; i++, j++)
{
dest[i] = src[j];
dest[i + 1] = '\0';
}
return (dest);
}
/**
 * _atoi - converts a string to an integer
 * @s: char  type pointer
 * Return: 0 if no number else the converted value
 */
int _atoi(char *s)
{
int i, sign = 1;
unsigned int n = 0;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == 45)
{
sign *= -1;
}
else if (s[i] >= 48 && s[i] <= 57)
{
n = (n * 10) + (s[i] - '0');
}
else if (n > 0)
	break;
}
return (sign * n);
}
