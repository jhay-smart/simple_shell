#include "shell.h"

/**
 * _strcat - This concatenates two strings
 * @dest: this char pointer the dest of the copied str
 * @src: this is a const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy -This copies the string pointed to by src.
 * @dest: This is a type char pointer the dest of the copied str
 * @src: This is a type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - This is a function that compares two strings.
 * @w1: type str compared
 * @w2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *w1, char *w2)
{
	int i;

	for (i = 0; w1[i] == w2[i] && w1[i]; i++)
		;

	if (w1[i] > w2[i])
		return (1);
	if (w1[i] < w2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @w: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *w, char c)
{
	unsigned int i = 0;

	for (; *(w + i) != '\0'; i++)
		if (*(w + i) == c)
			return (w + i);
	if (*(w + i) == c)
		return (w + i);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @w: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *w, char *accept)
{
	int i, j, bool;

	for (i = 0; *(w + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(w + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
