#include "main.h"
/**
 * _putchar - pass char to stdout
 * @c: passed char
 * Return: success or fail
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUFFER_CLEAR || i >= OUTPUT_BUF_SIZE)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != BUFFER_CLEAR)
		buf[i++] = c;
	return (1);
}
/**
 * _puts - print passed string
 * @str: string to be printed
 * Return: number of chars printed
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
	{
		_putchar(*str++);
	}
	return (str - a);
}
/**
 * print_to - print
 * @start: start
 * @end: end
 * @except: exception
 * Return: length
 */
int print_to(char *start, char *end, char *except)
{
	int sum = 0;

	while (start <= end)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
		
	}
	return (sum);
}
/**
 * get_print_func - finds format func
 * @s: string
 * @ptr: pointr
 * @params: parameters
 * Return: length
 */
int get_print_func(char *s, va_list ptr, params_t *params)
{
	int (*f)(va_list, params_t *) = handel(s);

	if (f)
		return (f(ptr, params));
	return (0);
}
/**
 * get_flag - find flag
 * @s: string
 * @params: parameters
 * Return: if flag valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}
