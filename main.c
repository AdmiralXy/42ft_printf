#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\n%d\n\n", printf("%.10s test\n", 0));
	printf("\n%d", ft_printf("%.10s test\n", 0));
}
