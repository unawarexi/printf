#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int count_digits(long num, long base)
{
	num = num >= 0 ? num : -(num);
	return (num < base ? 1 : 1 + count_digits(num/base, base));
}

char *conv_base(unsigned long num, unsigned long base)
{
	char base_case[] = "0123456789ABCDEF";
	int len = count_digits(num, base);
	char *result = malloc(len + 1);
	
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
	long int num, base;
	char *res;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	
	num = atol(argv[1]);
	base = atol(argv[2]);

	res = conv_base(num, base);
	printf("%s\n", res);
	free(res);
	return(0);
}

