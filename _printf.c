#include "main.h"
/**
 * _printf - function printf
 * @format: the format given
 * Return: length of chars output
 */
int _printf(const char *format, ...)
{
	int sum;
	char *p, *start;
	params_t params = PARAMS_INIT;
	va_list ptr;

	va_start(ptr, format);
	if (!format)
		return (-1);
	sum = 0;
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ptr);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
			p++;
		p = get_width(p, &params, ptr);
		p = get_precision(p, &params, ptr);
		if (get_modifier(p, &params))
			p++;
		if (!handel(p))
			sum += print_to(start, p, params.l_modifier || params.h_modifier ?
					p - 1 : 0);
		else
			sum += get_print_func(p, ptr, &params);
	}
	_putchar(BUFFER_CLEAR);
	va_end(ptr);
	return (sum);
}

