#include "main.h"
/**
 * print_unsigned - prints unsigned integer numbers
 * @ptr: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_unsigned(va_list ptr, params_t params)
{
	unsigned long l;

	if (params.l_modifier)
		l = (unsigned long) va_arg(ptr, unsigned long);
	else if (params.h_modifier)
		l = (unsigned short int) va_arg(ptr, unsigned int);
	else
		l = (unsigned int) va_arg(ptr, unsigned int);
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), &params));
}
/**
 * print_address - prints address
 * @ptr: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_address(va_list ptr, params_t params)
{
	unsigned long int n = va_arg(ptr, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, &params));
}
/**
 * print_number - pr
 * @str: the base number as a string
 * @params: the parameter struct
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}
/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ptr: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_hex(va_list ptr, params_t params)
{
	unsigned long l;
	char *str;

	if (params.l_modifier)
		l = (unsigned long) va_arg(ptr, unsigned long);
	else if (params.h_modifier)
		l = (unsigned short int) va_arg(ptr, unsigned int);
	else
		l = (unsigned int) va_arg(ptr, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params.hashtag_flag && l)
	{
	*--str = 'x';
	*--str = '0';
	}
	params.unsign = 1;
	return (print_number(str, &params));
}
/**
 * print_number_right_shift - df
 * @str: string
 * @params: the parameter struct
 * Return: chars printed
 */
int print_number_right_shift(char *s, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = strlen(s);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *s == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		s++;
	else
		neg = 0;
	if ((params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag &&
			!neg2 && !params->unsign && params->zero_flag)
		n += _putchar('-');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag &&
			!neg2 && !params->unsign && params->zero_flag)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}
