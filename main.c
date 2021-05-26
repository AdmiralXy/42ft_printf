#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("\n%d\n\n", printf("%.55X\n", 1234));
	printf("\n%d", ft_printf("%.55X\n", 1234));
}