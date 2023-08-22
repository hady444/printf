#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/*
 * #define BUFFER_SIZE 1024
#define BUFFER_CLEAR -1
#define INTIATE_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

typedef struct parameters
{
	unsigned int plus_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
	unsigned int width;
	unsigned int precision;
} params_t;
typedef strcut format_type
{
	char specifier;
	int (*fun)(va_list, char[], int, int, int, int);
} fmt;
*/
int _printf(const char *format, ...);
/**printers*/
int _putchar(int c);
int _puts(char *str);

/*print functions*/
/*
 * int print_char(va_list ptr, params_t *params);
 */
int printchar(char c);
int printpercent();
int printstring(const char* str);
int printinteger(int num);

#endif
