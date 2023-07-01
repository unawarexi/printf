#include "main.h"
#include <limits.h>

/**
 * count_digits - Count the number of digits in the required base.
 * @num: The number.
 * @base: Required base.
 *
 * Return: Number of digits.
 */
int count_digits(long num, long base)
{
	num = num >= 0 ? num : -(num);
	return (num < base ? 1 : 1 + count_digits(num / base, base));
}

/**
 * digTostr - Convert a number to a string.
 * @num: The number.
 *
 * Return: String representation of the number.
 */
char *digTostr(long num)
{
	int lenStr = num < 0 ? 1 : 0;
	char *str;

	lenStr += (count_digits(num, 10));

	str = malloc(sizeof(*str) * (lenStr + 1));
	if (!str)
		return (NULL);

	str[lenStr--] = '\0';
	str[0] = num >= 0 ? '0' : '-';
	num = num >= 0 ? num : -(num);

	while (num)
	{
		str[lenStr--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/**
 * conv_base - Convert a number to the required base.
 * @num: Number in base 10.
 * @base: New base.
 *
 * Return: New number in the required base.
 */
char *conv_base(size_t num, size_t base)
{
	char base_case[] = "0123456789ABCDEF";
	int len = num < ULONG_MAX ? count_digits(num, base) : c_count_dig(num, base);
	char *result = malloc(len + 1);

	result[len] = '\0';
	while (len)
	{
		result[--len] = base_case[num % base];
		num /= base;
	}
	return (result);
}

/**
 * rot13 - Encode a string using the ROT13 cipher.
 * @s: String to be encoded.
 *
 * Return: The resulting encoded string.
 */
char *rot13(char *s)
{
	int i, j;
	char *str, *sC;
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	sC = s ? s : "(null)";
	str = malloc(sizeof(*str) * (strlen(sC) + 1));

	if (!str)
		return (NULL);
	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			j = 0;
			while (a[j] != '\0')
			{
				if (s[i] == a[j])
				{
					str[i] = b[j];
					break;
				}
				else
					str[i] = s[i];
				j++;
			}
			i++;
		}
	}
	else
		strcpy(str, sC);
	return (str);
}
/**
 * rev_string - Reverse a string.
 * @s: Pointer to the string.
 *
 * Return: Reversed string.
 */
char *rev_string(char *s)
{
	char *sC, *str;
	int i = 0, len;

	sC = s ? s : "(null)";
	str = malloc(sizeof(*str) * (strlen(sC) + 1));

	if (!str)
		return (NULL);
	len = strlen(sC);
	if (s)
	{
		while (s[i])
		{
			str[len - 1 - i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	else
		strcpy(str, sC);
	return (str);
}
