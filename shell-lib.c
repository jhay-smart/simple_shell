#include "shell.h"

/**
* get_len - This helps to get the length of a number.
* @num: This type int number.
* Return: Length of the number.
*/
int get_len(int num)
{
unsigned int num1;
int length = 1;

if (num < 0)
{
length++;
num1 = num * -1;
}
else
{
num1 = num;
}
while (num1 > 9)
{
length++;
num1 = num1 / 10;
}

return (length);
}

/**
* aux_itoa - function converts int to string.
* @num: type int number
* Return: String.
*/
char *aux_itoa(int num)
{
unsigned int num1;
int length = get_len(num);
char *buffer;

buffer = malloc(sizeof(char) * (length + 1));
if (buffer == NULL)
return (NULL);

buffer[length] = '\0';

if (num < 0)
{
num1 = num * -1;
buffer[0] = '-';
}
else
{
num1 = num;
}

length--;
do {
buffer[length] = (num1 % 10) + '0';
num1 = num1 / 10;
length--;
} while (num1 > 0);

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
oi = oi + ((*(w + i) - '0') * m);
m /= 10;
}
return (oi *pn);
}

