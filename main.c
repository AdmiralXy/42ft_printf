#include "ft_printf.h"

int	main(void)
{
	printf("\n%d\n\n", printf("|%x|", LONG_MIN));
	printf("\n%d\n", ft_printf("|%p|", -1));
	return (1);
}
