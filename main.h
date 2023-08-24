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
#endif
