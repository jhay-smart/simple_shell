#include "shell.h"

/**
* free_data - frees data structure
*
* @datash: data structure
* Return: no return
*/
void free_data(data_shell *datash)
{
unsigned int x;

for (x = 0; datash->_environ[x]; x++)
{
free(datash->_environ[x]);
}

free(datash->_environ);
free(datash->pid);
}

/**
* set_data - Initialize data structure
*
* @datash: data structure
* @av: argument vector
* Return: no return
*/
void set_data(data_shell *datash, char **av)
{
unsigned int x;

datash->av = av;
datash->input = NULL;
datash->args = NULL;
datash->status = 0;
datash->counter = 1;

for (x = 0; environ[x]; x++);

datash->_environ = malloc(sizeof(char *) * (x + 1));

for (x = 0; environ[x]; x++)
{
datash->_environ[x] = _strdup(environ[x]);
}

datash->_environ[x] = NULL;
datash->pid = aux_itoa(getpid());
}

/**
* main - This is the entry point of this project
*
* @ac: This is the argument  count
* @av: This is the argument vector
*
* Return: 0 on success.
*/
int main(int ac, char **av)
{
data_shell datash;
(void) ac;

signal(SIGINT, signal_handler);
set_data(&datash, av);
shell_loop(&datash);
free_data(&datash);
if (datash.status < 0)
return (255);
return (datash.status);
}
