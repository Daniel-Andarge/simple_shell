#include "main.h"
/**
 * _realloc - eallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: previous memory size
 * @new_size: new memory size
 * Return: pointer to the  new memory
 * if new_size = 0, NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *hstr = (char *)ptr;
char *nstr;
unsigned int i;

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (new_size > old_size || ptr == NULL)
{
nstr = malloc(new_size);
if (nstr == NULL)
	return (NULL);
if (ptr != NULL)
{
for (i = 0; i < old_size; i++)
	nstr[i] = hstr[i];
}
}
else if (new_size == old_size)
	return (ptr);
	free(ptr);
	return (nstr);
}
/**
 * _reallocdp - realloc for double pointers
 * @ptr: double pointer to the memory
 * @old_size: old size
 * @new_size: new size
 * Return: ptr on success and NULL on failure
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
char **newptr;
unsigned int i;

if (ptr == NULL)
	return (malloc(sizeof(char *) * new_size));
if (new_size == old_size)
	return (ptr);

newptr = malloc(sizeof(char *) * new_size);
if (newptr == NULL)
	return (NULL);

for (i = 0; i < old_size; i++)
	newptr[i] = ptr[i];

free(ptr);

return (newptr);
}
