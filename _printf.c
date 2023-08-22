#include "main.h"
/**
 * _printf - function printf
 * @format: the format given
 * Return: length of chars output
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				count += printchar(va_arg(args, int));
			}
			else if (*format == 's')
			{
				count += printstring(va_arg(args, char*));
			}
			else if (*format == 'd' || *format == 'i')
			{
				count += printinteger(va_arg(args, int));
			}
			else if (*format == 'b')
			{
				count += printbinary(va_arg(args, int));
			}
			else if (*format == '%')
				count += printpercent();
		}
		else
			count += printchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
/*
 * int _printf(const char *format, ...)
{
	int sum;
	char *p, *start;

	va_list ptr;

	va_start(ptr, format);
	if (!format)
		return (-1);
	sum = 0;
	for (p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		if (!get_specifier(p))
	sum += print_to(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ptr, &params);
	}
	_putchar(BUFFER_CLEAR);
	va_end(ptr);
	return (sum);
}
*/
