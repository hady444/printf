#include "main.h"
/**
 * _putchar - pass char to stdout
 * @c: passed char
 * Return: success or fail
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - print passed string
 * @str: string to be printed
 * Return: number of chars printed
 */
int _puts(char *str)
{
	unsigned int i = 0;
	while (str[i] != '/0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

