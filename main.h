#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

int _putnbr(int n);
int _printf(const char *format, ...);
int _putchar(char c);
int _putnbr_binary(unsigned int n);
int _size(unsigned int nb);
int _putstr(const char *str);
#endif
