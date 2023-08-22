#include "main.h"
/**
 * printchar - Prints a single character to the standard output
 * @c: The character to be printed
 *
 * Return: The number of characters printed (always 1 in this case)
 */
int printchar(char c)
{
	_putchar(c);
	return (1);
}
/**
 * printpercent - Prints the percentage symbol ("%") to the standard output
 *
 * Return: The number of characters printed (always 1 in this case)
 */
int printpercent(void)
{
	_putchar('%');
	return (1);
}
/**
 * printstring - Prints a null-terminated string to the standard output
 * @str: The null-terminated string to be printed
 *
 * Return: The number of characters printed
 */
int printstring(const char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
/**
 * printinteger - Prints an integer to the standard output
 * @num: The integer to be printed
 *
 * Return: The number of characters printed
 */
int printinteger(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num >= 10)
	{
		count += printinteger(num / 10);
	}
	_putchar('0' + num % 10);
	return (count + 1);
}
int printbinary(unsigned int n)
{
	int count = 0, i;

	for (i = 0; i < 32; i++) {
		_putchar((n & (1 << i)) ? '1' : '0');
		count++;
	}
	return (count);
}
