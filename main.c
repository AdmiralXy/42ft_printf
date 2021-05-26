#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ncm_p;

	ncm_p = 0x20F;
	printf("\n%d\n\n", printf("%-0.2d", ncm_p));
	printf("\n%d", ft_printf("%-0.2d", ncm_p));
}
