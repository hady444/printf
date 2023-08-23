#include "main.h"
/**
 * get_modifier - modifiers
 * @s: s
 * @params: p
 * Return: length
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}
/**
 * get_width - gets the width from the format string
 * @s:¯the format string
 * @params: the parameters struct
 * @ptr: the argument pointer
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ptr)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ptr, int);
		s++;
	}
	else
	{
		while (isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
/**
* get_precision - gets the precision from the format string
* @p: the format string
* @params: the parameters struct
* @ptr: the argument pointer
* Return: new pointer
*/
char *get_precision(char *p, params_t *params, va_list ptr)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ptr, int);
		p++;
	}
	else
	{
		while (isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
/**
 * convert - converter function,
 * @num: number
 * @base: base
 * @flags: flag
 * @params: argf
 * Return: aparamater structstring
 */
char *convert(long int num, int base, int flags, params_t params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void) params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
	*--ptr = array[n % base];
	n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
