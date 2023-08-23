#include "main.h"
/**
 * handel - try to handel matching function
 * @s: given string
 * Return: length
 */
int (*handel(char *s))(va_list ptr, params_t *params)
{
	int i = 0;

	specifier_t specifierr[] = {
		{'c', print_char},
		{'d', print_integer},
		{'i', print_integer},
		{'s', print_string},
		{'%', print_percent},
		{'b', print_binary},
		{'p', print_address},
		{'u', print_unsigned},
		{'X', print_HEX},
		{'x', print_hex},
		{'o', print_octal},
		{'r', print_rev},
		{'S', print_S},
		{'R', print_rot13},
		{'\0', NULL}
	};

	while (specifierr[i].specifier)
	{
		if (specifierr[i].specifier == s[0])
			return (specifierr[i].fun);
		i++;
	}
	return (NULL);
}

