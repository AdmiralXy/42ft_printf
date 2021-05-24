#include "ft_printf.h"

int	main(void)
{
	printf("\n%d\n\n", printf("|%10c|", 'A'));
	printf("\n%d\n", ft_printf("|%10c|", 'A'));
	return (1);
}
