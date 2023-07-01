#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int count_digits(unsigned long num, unsigned long base)
{
	return (num < base ? 1 : 1 + count_digits(num/base, base));
}

int cToNum(char c)
{
	char alpha_num[] = "ABCDEFabcdef"

	if (c >= '0' && c <= '9')
		return (c - '0');
	while (alpha_num[i])
		if (alpha_num[i++] == c)
			return (10 + ((i - 1) % 5));
	return (-1);
}

char *_base10(char *num, int base)
{
	int len = 
	char *result = malloc(sizeof(*result) * (strlen(num) + 1));
	
	result[len] = '\0';
	while(len)
	{
		result[--len] = base_case[num%base];
		num /= base;
	}
	return(result);
}

int main(__attribute__((unused))int argc, char *argv[])
{
	if (argc !== 3)
	{
		printf("Invalid parameters\n");
		return (1);
	}

	long int base = atol(argv[2]);
	
	if (base > 16 || base < 1)
	{
		printf("Invalid parameters\n");
		return (1);
	}
	printf("%s\n", _base10(argv[1], base));
	return(0);
}

