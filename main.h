#ifndef _MAIN_H_
#define _MAIN_H_

#define MAXCOM 1000
#define BUFFER 1024
#define MAXLIST 100

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <string.h>

extern char **environ;
/**
 * struct store - contains some set data
 * @_environ: environment variables
 * @callmemaybe: argv[0]
 */
typedef struct store
{
char **_environ;
char *callmemaybe;
} store;

void execArg(char **command, char *name);
int _strcmp(char *s1, char *s2);
int storeinput(char *str);
char *_strcpy(char *dest, char *src);
void split_space(char *str, char **command);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int cpathandexec(char **command, store *data);
int cknowncommand(char **command, store *data);
void _puts(char *str);
int _putchar(char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buf, size_t j);
unsigned int is_delim(char c, char *delim);
char *_strtok(char *str, char *delim);
int _atoi(char *s);
char *_strdup(char *str);
char *remove_comment(char *str);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, store *data);
int _csetenv(char **command, store *data);
void set_data(store *data, char *name);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
int _unsetenv(char **command, store *data);
void rev_string(char *s);
int cd_exec(char **command, store *data);
void cd_to_home(store *data);
void cd_previous(store *data);
void cd_to(char **command, store *data);
void cd_dot(char **command, store *data);
char *_getenv(const char *name, char **_environ);
int cmp_env_name(const char *nenv, const char *name);

#endif
