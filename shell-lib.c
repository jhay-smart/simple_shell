#include "shell.h"

/**
* get_length - This helps to get the length of a number.
* @num: This type int number.
* Return: Length of the number.
*/
int get_len(int num)
{
unsigned int num1;
int lenght = 1;

if (num < 0)
{
lenght++;
num1 = num * -1;
}
else
{
num1 = num;
}
while (num1 > 9)
{
lenght++;
num1 = num1 / 10;
}

return (lenght);
}
/**
* aux_itoa - function converts int to string.
* @num: type int number
* Return: String.
*/
char *aux_itoa(int num)
{
unsigned int num1;
int lenght = get_len(num);
char *buffer;

buffer = malloc(sizeof(char) * (lenght + 1));
if (buffer == 0)
return (NULL);

*(buffer + lenght) = '\0';

if (num < 0)
{
num1 = num * -1;
buffer[0] = '-';
}
else
{
num1 = num;
}

lenght--;
do {
*(buffer + lenght) = (num1 % 10) + '0';
num1 = num1 / 10;
lenght--;
}	
while (num1 > 0);
{
return (buffer);
}

/**
* _atoi - This converts a string to an integer.
* @w: An input string.
* Return: An integer.
*/
int _atoi(char *w)
{
unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;
while (*(w + count) != '\0')
{
if (size > 0 && (*(w + count) < '0' || *(w + count) > '9'))
break;

if (*(w + count) == '-')
pn *= -1;

if ((*(w + count) >= '0') && (*(w + count) <= '9'))
{
if (size > 0)
m *= 10;
size++;
}
count++;
}
for (i = count - size; i < count; i++)
{
oi = oi + ((*(w + i) - 48) *m);
m /= 10;
}
return (oi * pn);
}
