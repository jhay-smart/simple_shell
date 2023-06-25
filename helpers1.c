#include "shell.h"

/**
* strcat_cd - function that concatenates the message for cd error
*
* @datash: data relevant (directory)
* @ermsg: Error message to print
* @error: output message
* @count_str: counter lines
* Return: error message
*/
char *strcat_cd(data_shell *datash, char *ermsg, char *error, char *count_str)
{
char *illegal_flag;

_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, count_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, ermsg);
if (datash->args[1][0] == '-')
{
illegal_flag = malloc(3);
illegal_flag[0] = '-';
illegal_flag[1] = datash->args[1][1];
illegal_flag[2] = '\0';
_strcat(error, illegal_flag);
free(illegal_flag);
}
else
{
_strcat(error, datash->args[1]);
}

_strcat(error, "\n");
_strcat(error, "\0");
return (error);
}

/**
* error_get_cd - error message for cd command in get_cd
* @datash: data relevant (directory)
* Return: Error message
*/
char *error_get_cd(data_shell *datash)
{
int length, len_id;
char *error, *count_str, *ermsg;

count_str = aux_itoa(datash->counter);
if (datash->args[1][0] == '-')
{
ermsg = ": Illegal option ";
len_id = 2;
}
else
{
ermsg = ": can't cd to ";
len_id = _strlen(datash->args[1]);
}

length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
length += _strlen(count_str) + _strlen(ermsg) + len_id + 5;
error = malloc(sizeof(char) * (length + 1));

if (error == 0)
{
free(count_str);
return (NULL);
}

error = strcat_cd(datash, ermsg, error, count_str);

free(count_str);

return (error);
}

/**
* error_not_found - generic error message for command not found
* @datash: data relevant (counter, arguments)
* Return: Error message
*/
char *error_not_found(data_shell *datash)
{
int length;
char *error;
char *count_str;

count_str = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(count_str);
length += _strlen(datash->args[0]) + 16;
error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(error);
free(count_str);
return (NULL);
}
_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, count_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, ": not found\n");
_strcat(error, "\0");
free(count_str);
return (error);
}

/**
* error_exit_shell - generic error message for exit in get_exit
* @datash: data relevant (counter, arguments)
*
* Return: Error message
*/
char *error_exit_shell(data_shell *datash)
{
int length;
char *error;
char *count_str;

count_str = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(count_str);
length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(count_str);
return (NULL);
}
_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, count_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, ": Illegal number: ");
_strcat(error, datash->args[1]);
_strcat(error, "\n\0");
free(count_str);

return (error);
}

