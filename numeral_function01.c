#include "main.h"

/**
 * print_hex - %h is taken care of by this
 * @arg: these are the Variadic Args
 *
 * Return: str with a pointer to it.
 */
char *print_hex(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = conv_base(num, 16);
	int i;

	if (!str)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			str[i] = str[i] + 32;
	}
	return (str);
}

/**
 * print_rot13 -  %R is taken care of by this
 * @arg: these are the variadic args
 *
 * Return: str with a pointer to it
 */
char *print_rot13(va_list arg)
{
	char *str = va_arg(arg, char *);
	char *rot_str;

	/**
	*strC = malloc(sizeof(*strC) * (strlen(str) + 1));
	if (!strC)
		return (NULL);
	*/
	rot_str = rot13(str);
	return (rot_str);

}

/**
 * print_rev_string - takes care of %r
 * @arg: these are the variadic args
 * Return: str with a pointer to it
 */
char *print_rev_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	char *rev_str;

	rev_str = rev_string(str);
	return (rev_str);
}
