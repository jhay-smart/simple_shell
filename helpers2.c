#include "shell.h"

/**
* error_env - This is the error message for env in get_env.
* @datash: data relevant (counter, arguments)
* Return: error message.
*/
char *error_env(data_shell *datash)
{
int length;
char *error;
char *counter_str;
char *errorMessage;

counter_str = aux_itoa(datash->counter);
errorMessage = ": Unable to add/remove from environment\n";
length = _strlen(datash->av[0]) + _strlen(counter_str);
length += _strlen(datash->args[0]) + _strlen(errorMessage) + 4;
error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(error);
free(counter_str);
return (NULL);
}

_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, counter_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, errorMessage);
_strcat(error, "\0");
free(counter_str);

return (error);
}
/**
* error_path_126 - error message for path and failure denied permission.
* @datash: data relevant (counter, arguments).
*
* Return: The error string.
*/
char *error_path_126(data_shell *datash)
{
int length;
char *counter_str;
char *error;

counter_str = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(counter_str);
length += _strlen(datash->args[0]) + 24;
error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(error);
free(counter_str);
return (NULL);
}
_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, counter_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, ": Permission denied\n");
_strcat(error, "\0");
free(counter_str);
return (error);
}

