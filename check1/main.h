#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

typedef struct Format_Specifier
{
	char c;
	void *(*func)(va_list args);
} specifier;

void *s_spec(va_list args);
int _printf(const char *format, ...);
void *c_spec(va_list args);

#endif
