#include "ft_printf.h"

int	main(void)
{
	printf("\n%d\n\n", printf("%u", -1));
	printf("\n%d\n", ft_printf("%u", -1));
	return (1);
}
