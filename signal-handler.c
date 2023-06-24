#include "shell.h"

/**
 * signal_handler - This is an integer that handles the crtl + c call in prompt
 * @sighdl: this is the Signal handler
 */
void signal_handler(int sighdl)
{
	(void)sighdl;
	write(STDOUT_FILENO, "\n^-^ ", 9);
}
