#include "ft_printf.h"

int	main(void)
{
	printf("\n%d\n\n", printf("|%%s%s%%|", "Hello"));
	printf("\n%d\n", ft_printf("|%%s%s%%|", "Hello"));
	return (1);
}
