int _printf(const char *format, ...)
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
