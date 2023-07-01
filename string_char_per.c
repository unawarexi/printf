#include "main.h"

/**
 * print_char - varaidic character value function
 * @arg: these are the variadic arguments.
 * Return: A null-byte str being terminated consisting of the char.
 */
char *print_char(va_list arg)
{
	char c = (char) va_arg(arg, int);
	char *str = malloc(sizeof(*str) + 1);

	if (!c)
	{
		str[0] = '\0';
		return (str);
	}
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';

	return (str);
}

/**
 * print_string - variadic str handler function
 * @arg: these are the  Variadic arguments.
 * Return: A terminated str of null_byte.
 */
char *print_string(va_list arg)
{
	char *str = va_arg(arg, char*);
	char *strC;

	str = str ? str : "(null)";

	strC = malloc(sizeof(*strC) * (strlen(str) + 1));
	if (!strC)
		return (NULL);
	strC = strcpy(strC, str);

	return (strC);
}

/**
 * print_percent - an escaped percent sign is been handled by this function
 * @arg:these are the  Variadic arguments.
 * Return: terminated str containg the percent null-byte.
 */
char *print_percent(__attribute__((unused))va_list arg)
{
	char *str = malloc(sizeof(*str) + 1);

	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
