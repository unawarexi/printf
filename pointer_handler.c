#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * c_count_dig - Count the number of digits in an unsigned number in the required base.
 * @num: The number.
 * @base: Required base.
 *
 * Return: Number of digits.
 */
int c_count_dig(size_t num, size_t base)
{
	return (num < base ? 1 : 1 + c_count_dig(num / base, base));
}

/**
 * custom_hex - Converts a decimal value to "0x + HEX value" format.
 * @value: The value to be converted.
 * Return: Pointer to a string containing the converted value.
 */

char *custom_hex(size_t value)
{

	int lenVal, i;
	char *str, *val_hex, *pad = "0x", *null_val = "(nil)";

	if (value)
	{
		lenVal = c_count_dig(value, 16);
		val_hex = conv_base(value, 16);

		str = malloc(sizeof(*str) * (lenVal + strlen(pad) + 1));
		if (!str)
			return (NULL);

		for (i = 0; val_hex[i]; i++)
		{
			if (val_hex[i] >= 'A' && val_hex[i] <= 'F')
				val_hex[i] = val_hex[i] + 32;
		}

		str[0] = '\0';

		str = strcat(str, pad);
		str = strcat(str, val_hex);

		free(val_hex);
	}
	else
	{
		str = malloc(sizeof(*str) * (strlen(null_val) + 1));
		if (!str)
			return (NULL);
		str[0] = '\0';
		strcpy(str, null_val);
	}
	return (str);
}

/**
 * print_pointer - Converts a variadic argument to a pointer-esque string using %p.
 * @args: Variadic list.
 * Return: Pointer to the string.
 */

char *print_pointer(va_list args)
{
	char *str;
	size_t val;

	val = va_arg(args, size_t);

	str = custom_hex(val);
	return (str);
}
