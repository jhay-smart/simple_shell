#include "shell.h"
/**
 * rev_string -This reverses a string.
 * @w: This is input string.
 * Return: no return.
 */
void rev_string(char *w)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (w[count] == '\0')
			break;
		count++;
	}
	str = w;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
