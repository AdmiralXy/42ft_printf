#include "ft_printf.h"

void ft_init_specs(t_specs *spec_info)
{
	spec_info->flag_minus = 0;
	spec_info->flag_zero = ' ';
	spec_info->width = 0;
	spec_info->precision = -1;
	spec_info->type = '\0';
	spec_info->negative = 0;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr_count(char *str, t_specs *spec_info)
{
	int i;

	i = 0;
	if (*str == '0' && spec_info->precision == 0)
	{
		ft_putchar(' ');
		return (1);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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