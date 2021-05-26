#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\n%d\n\n", printf("%0.*i test\n", 5, 0));
	printf("\n%d", ft_printf("%0.*i test\n", 5, 0));
}
