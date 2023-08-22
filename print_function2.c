#include "main.h"
#include "string.h"
/**
 * _printf_octal - octal convertor
 * @format: format
 * Return: length
 */
int _printf_octal(const char *format, ...)
{
	va_list args;
	int charCount = 0, i;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'o')
			{
				unsigned int value = va_arg(args, unsigned int);
				char buffer[32];

				snprintf(buffer, sizeof(buffer), "%o", value);
				for (i = 0; buffer[i] != '\0'; i++)
				{
					putchar(buffer[i]);
					charCount++;
				}
			}
		}
		else
		{
			putchar(*format);
			charCount++;
		}
		format++;
	}
	va_end(args);
	return (charCount);
}
/**
 * _printf_HEX - Hexa convertor
 * @format: format
 * Return: length
 */
int _printf_HEX(const char *format, ...)
{
	va_list args;
	int charCount = 0, i;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'x')
			{
				unsigned int value = va_arg(args, unsigned int);
				char buffer[32];

				snprintf(buffer, sizeof(buffer), "%x", value);
				for (i = 0; buffer[i] != '\0'; i++)
				{
					putchar(buffer[i]);
					charCount++;
				}
			}
		}
		else
		{
			putchar(*format);
			charCount++;
		}
		format++;
	}
	va_end(args);
	return (charCount);
}
/**
 * _printf_reverse - rerverse oeder
 * @format: format
 * Return: length
 */
int _printf_reverse(const char *format, ...)
{
	va_list args;
	int charCount = 0, i;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'r')
			{
				char *str = va_arg(args, char *);
				int length = strlen(str);

				for (i = length - 1; i >= 0; i--)
				{
					putchar(str[i]);
					charCount++;
				}
			}
		}
		else
		{
			putchar(*format);
			charCount++;
		}
		format++;
	}
	va_end(args);
	return (charCount);
}
