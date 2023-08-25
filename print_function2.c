#include "main.h"
/**
 * print_octal - octal convertor
 * @ptr: format
 * @params: fdg
 * Return: length
 */
int print_octal(va_list ptr, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long) va_arg(ptr, unsigned long);
	else if (params->h_modifier)
	l = (unsigned short int) va_arg(ptr, unsigned int);
	else
		l = (unsigned int) va_arg(ptr, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_HEX - Hexa convertor
 * @ptr: format
 * @params: fgf
 * Return: length
 */
int print_HEX(va_list ptr, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long) va_arg(ptr, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int) va_arg(ptr, unsigned int);
	else
		l = (unsigned int) va_arg(ptr, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_rev - rerverse oeder
 * @ptr: valist
 * @params: parameters
 * Return: length
 */
int print_rev(va_list ptr, params_t *params)
{
	int charCount = 0, i;
	char *str = va_arg(ptr, char *);
	(void) params;

	if (str)
	{
		for (i = 0; *str; str++)
			i++;
		str--;
		for (; i > 0; i--, str--)
			charCount += _putchar(*str);
	}
	return (charCount);
}
/**
 * print_S - print
 * @ptr: valist
 * @params: parameters
 * Return: length
 */
int print_S(va_list ptr, params_t *params)
{
	char *str = va_arg(ptr, char *);
	char *hex;
	int sum = 0;

	if ((int) (!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
			sum += _putchar(*str);
	}
	return (sum);
}
/**
 * print_rot13 - print
 * @ptr: valist
 * @params: parameters
 * Return: length
 */
int print_rot13(va_list ptr, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM    nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ptr, char *);
	(void) params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
