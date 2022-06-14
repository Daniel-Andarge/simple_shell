#include "main.h"
/**
 * execArg - executes commands
 * @command: command to execute
 * @name: argv[0]
 */
void execArg(char **command, char *name)
{
struct stat st;
pid_t pid;

if (stat(command[0], &st) == 0)
{
pid = fork();
if (pid == -1)
{
perror("Error");
return;
}
else if (pid == 0)
{
if (execve(command[0], command, NULL) == -1)
	perror(name);
exit(0);
}
else
{
wait(NULL);
return;
}
}
else
{
if (execve(command[0], command, NULL) == -1)
	perror(name);
return;
}
}
/**
 * cknowncommand - checks if command is known
 * @command: command to check
 * Return: 1 if not known
 */
int cknowncommand(char **command, store *data)
{
int i, check = 0, x, y, n;
char *knowncommand[5] = {"exit", "env", "setenv", "unsetenv", "cd"};

x = _strcmp(command[0], "/usr/bin/env");
y = _strcmp(command[0], "/bin/env");
for (i = 0; i < 5; i++)
{
if (_strcmp(command[0], knowncommand[i]) == 0)
{
check = i + 1;
break;
}
}
if (check == 1)
{
if (!command[1])
	n = 0;
else
	n = _atoi(command[1]);
exit(n);
}
if (check == 2 || !x || !y)
{
for (i = 0; data->_environ[i]; i++)
	_puts(data->_environ[i]);
return (2);
}
if (check == 3)
{
_csetenv(command, data);
return(3);
}
if (check == 4)
{
_unsetenv(command, data);
return(4);
}
if (check == 5)
{
cd_exec(command, data);
return(5);
}
return (1);
}
/**
 * cpathandexec - checks if PATH was written in command
 * and edits if necessary
 * @command: command to execute
 * @name: argv[0]
 * Return: 0 on success and 1 on failure
 */
int cpathandexec(char **command, store *data)
{
struct stat st;
int x, y, z;
char hold[PATH_MAX] = "/usr/bin/";

y = _strcmp(command[0], "/usr/bin/env");
z = _strcmp(command[0], "/bin/env");
if (stat(command[0], &st) == 0 && y && z)
	execArg(command, data->callmemaybe);
else
{
x = cknowncommand(command, data);
if (x == 1)
{
_strcat(hold, command[0]);
command[0] = hold;
execArg(command, data->callmemaybe);
}
}
return (0);
}
