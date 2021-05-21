#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello world! %d %d %d %c\n", 1337, INT32_MAX, INT32_MIN);
	printf("Hello world! %d %d %d\n", 1337, INT32_MAX, INT32_MIN);
	return (1);
}
