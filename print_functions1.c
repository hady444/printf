#include "main.h"
/**
 * print_char - print character
 * @ptr: the va_list of _printf function
 * @params: the parameters passed to function
 * Return: number of printed chars
 */
int print_char(va_list ptr, params_t *params)
{
	unsigned int sum = 0, padding = 1, c = va_arg(ptr, int);
	if (params->MINUS_FLAG)
		sum += _putchar(c);
	while (padding < params->width)
	{
		sum += _putchar(' ');
		padding++;
	}
	if (!params->MINUS_FLAG)
		sum += _putchar(c);
	return (sum);
}
