#include "ft_printf.h"

int	main(void)
{
	printf("\n%d\n\n", printf("|%-22s|", "Hello"));
	printf("\n%d\n", ft_printf("|%-22s|", "Hello"));
	return (1);
}
