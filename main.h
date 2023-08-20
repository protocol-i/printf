#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef struct printf_utils {
	int (*_size)(unsigned int);
	int (*_putnbr)(int);
	int (*_printf)(const char *, ...);
} PrintfUtils;

int _size(unsigned int nb);
int _putnbr(int n);
int _printf(const char *format, ...);

#endif
