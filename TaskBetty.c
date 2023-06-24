#include <stdio.h>

/**
 * print_alphabets - This Prints the lowercase alphabet in ascending order
 *
 * Return: None
 */
void print_alphabets(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	putchar('\n');
}

/**
 * main - Entry point of the program
 *
 * Return: this returns 0 on success
 */
int main(void)
{
	print_alphabets();

	return 0;
}
