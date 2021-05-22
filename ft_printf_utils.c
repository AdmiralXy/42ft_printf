#include "ft_printf.h"

void ft_init_specs(t_specs *spec_info)
{
	spec_info->flag_minus = 0;
	spec_info->flag_zero = 0;
	spec_info->width = 0;
	spec_info->precision = 0;
	spec_info->type = '\0';
}

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

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (0);
}