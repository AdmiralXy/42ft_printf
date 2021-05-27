#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\n%d\n\n", printf("%14c", 'A'));
	printf("\n%d", ft_printf("%14c", 'A'));
}
