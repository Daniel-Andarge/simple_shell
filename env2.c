#include "main.h"
/**
 * cmp_env_name - comapres variable names
 * @nenv: variable name
 * @name: name passed
 * Return: 0 if not equal, >0 if they are
 */
int cmp_env_name(const char *nenv, const char *name)
{
int i;

for (i = 0; nenv[i] != '='; i++)
{
if (nenv[i] != name[i])
	return (0);
}
return (i + 1);
}
/**
 * _getenv - gets the value of an environment variable
 * @name: name of the variable
 * @_environ: environment value
 * Return: value of the variable if found
 * else NULL
 */
char *_getenv(const char *name, char **_environ)
{
char *ptr_env;
int i, mov;

ptr_env = NULL;
mov = 0;

for (i = 0; _environ[i]; i++)
{
mov = cmp_env_name(_environ[i], name);
if (mov)
{
	ptr_env = _environ[i];
	break;
}
}
return (ptr_env + mov);
}
