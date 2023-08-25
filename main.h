#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

int _putnbr(int n);
int _printf(const char *format, ...);
int _putchar(char c);
int _putnbr_binary(unsigned int n);
int _putnbr_binary_recursive(unsigned int n);
int _size(unsigned int nb);
int _putstr(const char *str);
int print_unsigned(unsigned int n);
int print_hex_lower(unsigned int n);
int print_octal(unsigned int n);
int print_hex_upper(unsigned int n);
<<<<<<< HEAD
int _print_number(int n);
int print_int(va_list args, const char *flags);
=======
int handle_S_specifier(va_list arg_list);
char to_hex_digit(unsigned char value);
>>>>>>> 80dfcc9c724eca9136290fb0ff13aa265d20026f
#endif
