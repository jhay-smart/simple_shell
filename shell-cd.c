#include "shell.h"

/**
* shell_cd - This changes current directory
*
* @datash: This represents relevant data
* Return: 1 on success
*/
int shell_cd(data_shell *datash)
{
char *dir;
int ishome, ishome2, isddash;

dir = datash->args[1];

if (dir != NULL)
{
ishome = _strcmp("$HOME", dir);
ishome2 = _strcmp("~", dir);
isddash = _strcmp("--", dir);
}

if (dir == NULL || !ishome || !ishome2 || !isddash)
{
cd_to_home(datash);
return (1);
}

if (_strcmp("-", dir) == 0)
{
cd_previous(datash);
return (1);
}

if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
{
cd_dots(datash);
return (1);
}

cd_to(datash);

return (1);
}
