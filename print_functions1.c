#include "main.h"
/**
 * print_char - Prints a single character to the standard output
 * @ptr: valist
 * @params: passed parameters
 *
 * Return: The number of characters printed (always 1 in this case)
 */
int print_char(va_list ptr, params_t *params)
{
	char padding = ' ';
	unsigned int pad = 1;
	unsigned int sum = 0;
	unsigned int ch = va_arg(ptr, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(padding);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}
/**
 * print_percent - Prints the percentage symbol ("%") to the standard output
 * @ptr: valist
 * @params: passed parameters
 * Return: The number of characters printed (always 1 in this case)
 */
int print_percent(va_list ptr, params_t *params)
{
	(void) ptr;
	(void) params;
	putchar('%');
	return (1);
}
/**
 * print_string - Prints a null-terminated string to the standard output
 * @ptr: valist
 * @params: passed parameters
 * Return: The number of characters printed
 */
int print_string(va_list ptr, params_t *params)
{
	char *str = va_arg(ptr, char *), padding = ' ';
	unsigned int sum = 0, pad = 0, i = 0, j;

	(void) params;
	switch ((int) (!str))
	case 1:
		str = NULL_STRING;

	j = pad = strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;
	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(padding);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}
/**
 * print_integer - Prints an integer to the standard output
 * @ptr: valist
 * @params: passed parameters
 * Return: The number of characters printed
 */
int print_integer(va_list ptr, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ptr, long);
	else if (params->h_modifier)
		l = (short int) va_arg(ptr, int);
	else
		l = (int) va_arg(ptr, int);
	return (print_number(convert(l, 10, 0, params), params));
}
/**
 * print_binary - Prints an integer to the standard output
 * @ptr: The integer to be printed
 * @params: fddf
 * Return: The number of characters printed
 */
int print_binary(va_list ptr, params_t *params)
{
	unsigned int n = va_arg(ptr, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
