#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>

#define NULL_STRING "(null)"
#define OUTPUT_BUF_SIZE 1024
#define BUFFER_CLEAR -1
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - Formatting parameters structure
 * @unsign: Flag indicating whether the format is for an unsigned value
 * @plus_flag: Flag indicating whether the plus sign should be displayed
 * @minus_flag: Flag indicating whether the minus sign should be displ
 * @space_flag: Flag indicating whether a space should be
 * @zero_flag: Flag indicating whether leading zeros should be displ
 * @hashtag_flag: Flag indicating whether the hashtag symbol
 * @h_modifier: Flag indicating whether the "h" length modifier is used
 * @l_modifier: Flag indicating whether the "l" length modifier is used
 * @width: The width field for formatting
 * @precision: The precision field for formatting
 * Description: This structure represents the parameter
 * It contains various flags and modifiers that contros
 * whether to display signs, leading zeros, or the has
 * width and precision fields for specifying the desi.
*/

typedef struct parameters
{
	unsigned int unsign : 1;
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

/**
 * struct specifier - Formatting specifier structure
 * @specifier: The character representing the specifier
 * @fun: Pointer to the formatting function for the specifier
 * Description: This structure represents a specifier used in formatting.
 */
typedef struct specifier
{
	char specifier;
	int (*fun)(va_list, params_t *);
} specifier_t;

int _printf(const char *format, ...);
int (*handel(char *s))(va_list ptr, params_t *params);
/**printers*/
int _putchar(int c);
int _puts(char *str);
int _isdigit(int c);
int _strlen(char *str);
/*print functions*/
/*
 * int print_char(va_list ptr, params_t *params);
 */
int print_char(va_list ptr, params_t *params);
int print_percent(va_list ptr, params_t *params);
int print_string(va_list ptr, params_t *params);
int print_integer(va_list ptr, params_t *params);
int print_binary(va_list ptr, params_t *params);
int print_unsigned(va_list ptr, params_t *params);
int print_address(va_list ptr, params_t *params);
int print_HEX(va_list ptr, params_t *params);
int print_hex(va_list ptr, params_t *params);
int print_octal(va_list ptr, params_t *params);
int print_S(va_list ptr, params_t *params);
int print_rev(va_list ptr, params_t *params);
int print_rot13(va_list ptr, params_t *params);
int print_to(char *start, char *stop, char *except);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ptr);
int get_print_func(char *s, va_list ptr, params_t *params);
char *convert(long int num, int base, int flag, params_t *params);
int print_number(char *s, params_t *params);
int print_number_right_shift(char *s, params_t *params);
int print_number_left_shift(char *s, params_t *params);
void init_params(params_t *params, va_list ptr);
char *get_precision(char *p, params_t *params, va_list ptr);
#endif
