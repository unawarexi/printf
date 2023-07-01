#ifndef _MAIN_H_
#define _MAIN_H_

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif /* BUF_SIZE */

typedef char* (*specifier_func)(va_list);

/**
  * struct specifier - A struc holding analysed char_values and function
  * @c: Char_value to spot format descriptor
  * @func: func to handle descriptor
  */

typedef struct specifier
{
	char c;
	specifier_func func;
} c_spe;

/**
  * struct return_string - A structure to hold vrdic string
  * @i: cummulative length of descriptor
  * @string: Str_value aligning to given descriptor.
  * Description: struc holds the length of a given descriptor
  * E.g. '.2f' makes i = 3. string holds the post-formatted string.
  */
typedef struct return_string
{
	int i;
	char *string;
} var_str;


int _printf(const char *format, ...);
var_str *check_sp(const char *format, va_list);
specifier_func ret_func(int i);

char *print_HEX(va_list arg);
char *print_char(va_list arg);
char *print_string(va_list arg);
char *print_percent(__attribute__((unused))va_list arg);
int count_digits(long num, long base);
char *digTostr(long num);
char *print_int(va_list arg);
char *print_u_int(va_list arg);
char *conv_base(size_t num, size_t base);
char *print_bin(va_list arg);
unsigned char *c_strcat(unsigned char *dest, unsigned char *src);
char *print_oct(va_list arg);
char *print_hex(va_list arg);
char *print_rot13(va_list arg);
char *rot13(char *s);
char *print_custom_string(va_list args);
int c_strlen(unsigned char *s);
char *print_pointer(va_list args);
int c_count_dig(size_t num, size_t base);
char *rev_string(char *s);
char *print_rev_string(va_list arg);
int isValid(char c);
void check_buffer(char *buffer, char *str);

#endif /* _MAIN_H_ */
