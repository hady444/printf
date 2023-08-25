#include "main.h"
/**
 * _isdigit - check numbers
 * @c: passed input
 * Return: 1 or 0
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - return length of string
 * @str: string
 * Return: int
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}
