#include "main.h"
/**
  * c_strcat - Concatenates two unsigned pointers to string.
  * @dest: Destination param.
  * @src: Source param.
  * Return: Pointer to resulting dest
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
  * c_strlen - Calculate the length of a string.
  * @s: The string to be printed.
  * Return: Length of a string
  */
int c_strlen(unsigned char *s)
{
	if (!*s)
		return (0);
	return (1 + c_strlen(s + 1));
}

