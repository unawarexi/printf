#include <stdio.h>
#include <string.h>
#include "main.h"

/**
  * isNotPrint - This function checks if a char is not printable
  * @c: Char to be checked
  * Return: 1 if it's not printable else 0.
  */

short int isNotPrint(unsigned char c)
{
	return ((c > 0 && c < 32) || c >= 127);
}

/**
  * c_count_str - A custom string length checker
  * @str: String to be checked
  * Return: Length of custom string
  */

int c_count_str(unsigned char *str)
{
	int len = 0;

	while (str && *str)
	{
		if (isNotPrint(*str))
			len += 4;
		else
			len += 1;
		str++;
	}
	return (len);
}

/**
  *_customS - This function converts ascii value to '\x + HEX value'
  *@ascii: The ascii value to be converted
  *Return: Pointer to a string containing thr converted value
  */

unsigned char *_customS(int ascii)
{
	unsigned char *str = malloc(sizeof(*str) * 5);
	unsigned char *ascii_hex = (unsigned char *)conv_base(ascii, 16);
	unsigned char pad[] = "\\x", c = 0;

	if (!str)
		return (NULL);

	if (!ascii_hex[1])
	{
		c = ascii_hex[0];
		free(ascii_hex);

		ascii_hex = malloc(sizeof(*ascii_hex) * 3);

		if (!ascii_hex)
			return (NULL);

		ascii_hex[0] = '0';
		ascii_hex[1] = c;
		ascii_hex[2] = '\0';
	}

	str[0] = '\0';
	str = c_strcat(str, pad);
	if (!ascii_hex || c_strlen(ascii_hex) > 2)
	{
		free(str);
		return (NULL);
	}
	str = c_strcat(str, ascii_hex);
	free(ascii_hex);
	return (str);
}

/**
  *print_custom_string - A function to conv vrdic
  *string to a custom string given %S.
  *@args: Variadic list.
  *Return: Pointer to string.
  */

char *print_custom_string(va_list args)
{
	unsigned char *str, *strC, *tmp, chr_stor[2] = {0};
	int lenStr, i = 0;

	str = va_arg(args, unsigned char*);
	str = str ? str : (unsigned char *) "(null)";
	lenStr = c_count_str(str);

	strC = malloc(sizeof(*strC) * (lenStr + 1));
	if (!strC)
		return (NULL);

	strC[lenStr] = '\0';
	while (str[i])
	{
		if (isNotPrint(str[i]))
		{
			tmp = _customS(str[i]);
			if (!tmp)
				return (NULL);
			c_strcat(strC, tmp);
			free(tmp);
		}
		else
		{
			chr_stor[0] = str[i];
			c_strcat(strC, chr_stor);
		}
		i++;
	}
	return ((char *)strC);
}

