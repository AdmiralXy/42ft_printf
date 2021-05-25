#include "ft_printf.h"

static int	ft_putstr_max(char *str, int n)
{
	int	i;

	if (n < 0)
		n = ft_strlen(str);
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static int	ft_strlen_max(const char *s, int n)
{
	int	i;

	if (n < 0)
		n = ft_strlen(s);
	i = 0;
	while (s[i] != '\0' && i < n)
		i++;
	return (i);
}

static int	ft_aligner(char *nbr, t_specs *spec_info)
{
	int	i;
	int	n;

	n = 0;
	if (spec_info->flag_minus)
		n += ft_putstr_max(nbr, spec_info->precision);
	i = 0;
	while (i++ < spec_info->width - ft_strlen_max(nbr, spec_info->precision))
	{
		ft_putchar(' ');
		n++;
	}
	if (!spec_info->flag_minus)
		n += ft_putstr_max(nbr, spec_info->precision);
	return (n);
}

int	ft_print_s(va_list *arg, t_specs *spec_info)
{
	char	*str;
	int		n;

	n = 0;
	str = va_arg(*arg, char *);
	n += ft_aligner(str, spec_info);
	return (n);
}
