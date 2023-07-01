#include <ctype.h>
#include "main.h"

/**
 * ret_func - Returns the corresponding function pertaining to a given index
 * @i: index
 * Return: The corresponding function
 */
specifier_func ret_func(int i)
{
	c_spe all_spe[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'b', print_bin},
		{'u', print_u_int},
		{'o', print_oct},
		{'x', print_hex},
		{'X', print_HEX},
		{'R', print_rot13},
		{'S', print_custom_string},
		{'p', print_pointer},
		{'r', print_rev_string},
		{'\0', NULL},
	};
	return (all_spe[i].func);
}

/**
 * isValid - This function checks if a given char is a valid format specifier
 * @c: The char to be checked
 * Return: -1 if not a valid specifier else its index in the struct of ret_func
 */

int isValid(char c)
{
	char *valid_specifiers = "cs%dibuoxXRSpr";
	int i = 0;

	while (valid_specifiers[i])
	{
		if (valid_specifiers[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * check_sp - This function returns a pointer to struct.
 * @format: The formatted string at a specific index
 * @args: Variadic arguments
 * Return: Struct containing str to print and offset i or NULL.
 */
var_str *check_sp(const char *format, va_list args)
{
	int i = 1, index;
	var_str *f;

	index = isValid(format[i]);
	if (index >= 0)
	{
		f = malloc(sizeof(var_str));
		if (!f)
			return (NULL);
		f->i = i;
		f->string = ret_func(index)(args);
		if (!f->string)
		{
			free(f);
			exit(-1);
		}
		return (f);
	}
	return (NULL);
	/**
	*while (format && format[i])
	{
		index = isValid(format[i]);
		if (index >= 0)
		{
			f = malloc(sizeof(var_str));
			if (!f)
				exit(98);

			f->i = i;
			f->string = ret_func(index)(args);
			return (f);
		}
		else if (isalpha(format[i]) || format[i + 1] == '%')
			return (NULL);
		i++;
	}
	return (NULL);
	*/
}
/**
 * check_buffer - checks to see if there enough space in buffer
 * @buffer: Buffer
 * @str: New string
 * Return: number of bytes written to stdout.
 */
void check_buffer(char *buffer, char *str)
{
	int buf_len = strlen(buffer);
	int str_len = strlen(str);

	if (buf_len + str_len >= BUF_SIZE)
	{
		write(1, buffer, buf_len);
		buffer[0] = 0;
	}
	strcat(buffer, str);
}

