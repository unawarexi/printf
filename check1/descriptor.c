#include  "main.h"

void *c_spec(va_list args)
{
	char *cp =  malloc(1);
	if (cp  ==NULL)
		return (NULL);
	cp[0] = va_arg(args, int);
	return (cp);
}

void *s_spec(va_list args)
{
	char *str = va_arg(args, char *);
	char *str_n = malloc(strlen(str));
	if (str_n == NULL)
	{
		free(str_n);
		return (NULL);
	}
	if (str == NULL)
		str_n = "";
	else
		strcat(str_n, str);
	return (str_n);
}

