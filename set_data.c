#include "main.h"
/**
 * set_data - sets environ data
 */
void set_data(store *data, char *name)
{
int i;

for (i = 0; environ[i]; i++)
	;
data->_environ = malloc(sizeof(char *) * (i + 1));

for (i = 0; environ[i]; i++)
	data->_environ[i] = _strdup(environ[i]);
data->_environ[i] = NULL;

data->callmemaybe = name;
}
