#include "main.h"

int (*fun(char *s))(va_list ap, params_t params)
{
	int i = 0;

	specifier_t specifier = {
		{'c', printchar},
		{'d', printinteger},
		{'i', printinteger},
		{'s', printstring},
		{'%', printpercent},
		{'b', printbinary},
		{NULL, NULL}}
	while (specifier[i].specifier)
	{
		if (specifier[i].specifier == s[0])
			return (specifier[i].fun);
		i++;
	}
	return (NULL);
}

