#include "shell.h"
/**
* buildin_handler - This is the builtin that pass the command in the arg
* @cmd: command
* Return: function pointer of the builtin command
*/
int (*buildin_handler(char *cmd))(data_shell *)
{
builtin_t builtin[] = {
{ "env", _env },
{ "exit", status_handler },
{ "setenv", _setenv },
{ "unsetenv", _unsetenv },
{ "cd", shell_cd },
{ "help", helpers },
{ NULL, NULL }
};
int i;

for (i = 0; builtin[i].name; i++)
{
if (_strcmp(builtin[i].name, cmd) == 0)
break;
}

return (builtin[i].f);
}

