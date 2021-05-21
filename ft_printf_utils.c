#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int second;

	second = nb % 10;
	if (nb < -9 || nb > 9)
		ft_putnbr(nb / 10);
	if (nb >= 0)
		ft_putchar('0' + second);
	else
	{
		if (nb <= 9 && nb >= -9)
			ft_putchar('-');
		ft_putchar('0' - second);
	}
}