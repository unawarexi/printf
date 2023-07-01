#include "main.h"
/**
 * c_strcat - Concatenates two strings by appending the source
 * string to the destination string.
 * @dest: Destination string.
 * @src: Source string.
 * Return: Pointer to the resulting destination string.
 */

unsigned char *c_strcat(unsigned char *dest, unsigned char *src)
{
	int destEnd = 0, i = 0, j = 0;

	while (src[j])
	{
		if (dest[i] == '\0' && !destEnd)
			destEnd = 1;
		if (destEnd)
		{
			dest[i] = src[j];
			j++;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * c_strlen - Calculates the length of a string.
 * @s: The string for which length is to be calculated.
 * Return: Length of the string.
 */
int c_strlen(unsigned char *s)
{
	if (!*s)
		return (0);				  /*Base case: empty string has length 0*/
	return (1 + c_strlen(s + 1)); /*recursive*/
}
