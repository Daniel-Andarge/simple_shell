#include "main.h"
/**
 * copy_info - copies value of var int var
 * @name: variable name
 * @value: variable value
 * Return: new env
 */
char *copy_info(char *name, char *value)
{
char *new;
int len_name, len_value, len;

len_name = _strlen(name);
len_value = _strlen(value);
len = len_name + len_value + 2;
new = malloc(sizeof(char) * len);
_strcpy(new, name);
_strcat(new, "=");
_strcat(new, value);
_strcat(new, "\0");

return (new);
}
/**
 * set_env - sets or modifies an environment variable
 * @name: variable name
 * @value: variable value
 */
void set_env(char *name, char *value, store *data)
{
int i;
char *var_env, *name_env;


for (i = 0; data->_environ[i]; i++)
{
var_env = _strdup(data->_environ[i]);
name_env = _strtok(var_env, "=");
if (_strcmp(name_env, name) == 0)
{
free(data->_environ[i]);
data->_environ[i] = copy_info(name_env, value);
free(var_env);
return;
}
free(var_env);
}
data->_environ = _reallocdp(data->_environ, i, sizeof(char *) * (i + 2));
data->_environ[i] = copy_info(name, value);
data->_environ[i + 1] = NULL;
}
/**
 * _csetenv - checks if setenv is correctly called
 * command - command passed
 * Return: 1 on success
 */
int _csetenv(char **command, store *data)
{
if (command[1] == NULL || command == NULL)
	write(STDERR_FILENO, "Failed\n", 7);
else
	set_env(command[1], command[2], data);
return (1);
}
/**
 * _unsetenv - deletes an environment variable
 * @command: command passed
 * Return: 1 on success
 */
int _unsetenv(char **command, store *data)
{
char **re_env;
char *var_env, *name_env;
int i, j, k;

if (command[1] == NULL)
{
write(STDERR_FILENO, "Failed\n", 7);
return (1);
}
k = -5;
for (i = 0; data->_environ[i]; i++)
{
var_env = _strdup(data->_environ[i]);
name_env = _strtok(var_env, "=");
if (_strcmp(name_env, command[1]) == 0)
	k = i;
free(var_env);
}
if (k == -5)
{
write(STDERR_FILENO, "Failed\n", 7);
return (1);
}
re_env = malloc(sizeof(char *) * i);
for (i = j = 0; data->_environ[i]; i++)
{
if (i != k)
{
re_env[j] = data->_environ[i];
j++;
}
}
re_env[j] = NULL;
free(data->_environ[k]);
free(data->_environ);
data->_environ = re_env;
return (1);
}
