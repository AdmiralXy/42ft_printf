#include "ft_printf.h"

int	main(void)
{
	printf("\n%d\n\n", printf("|%u|", -123));
	printf("\n%d\n", ft_printf("|%u|", -123));
	return (1);
}
