#include "main.h"


int _printf(const char *format, ...)
{
	specifier arr[] = {
		{'c', c_spec},
		{'s', s_spec},
		{'\0', NULL},
	};
	va_list args;
	void *(*func)(va_list args) = NULL;
	int i = 0, j;
	char *str = malloc(1024), c[1], *sub;
	va_start(args, format);

	if (format != NULL)
	{
		while(format[i] != '\0')
		{
			if (format[i] == '%')
			{
				j = 0;
				while(arr[j].c !=  '\0')
				{
					if (arr[j].c == format[i + 1])
						func = arr[j].func;
					j++;
				}
				if (func)
				{
					sub = func(args);
					if (sub != NULL)
					{
						strcat(str, sub);
						free(sub);
					}
				}
				if (format[i + 1] == '%')
				{
					c[0] = format[i];
					strcat(str, c);
				}
				if (format[i + 1] == 'r')
				{
					c[0] = format[i];
					strcat(str, c);
					c[0] = format[i + 1];
					strcat(str, c);
				}
				i++;

			}
			else
			{
				c[0] = format[i];
				strcat(str, c);
			}
			i++;
		}
	}
	write(1, str, strlen(str));
	free(str);
	va_end(args);
	return (0);
}

