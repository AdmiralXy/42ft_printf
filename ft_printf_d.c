#include "ft_printf.h"

int	ft_strlen_minus(const char *s, int n)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i - n);
}

char	*ft_precision(char *nbr, t_specs *spec_info)
{
	char	*nbr_prec;
	int		nbr_len;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = spec_info->precision + spec_info->negative + 1;
	nbr_len = ft_strlen_minus(nbr, spec_info->negative);
	if (spec_info->precision > nbr_len)
	{
		nbr_prec = malloc(sizeof(char) * size);
		if (spec_info->negative && ++j)
			nbr_prec[i++] = '-';
		while (i < spec_info->precision + spec_info->negative - nbr_len)
			nbr_prec[i++] = '0';
		while (i < spec_info->precision + spec_info->negative)
			nbr_prec[i++] = nbr[j++];
		nbr_prec[i] = '\0';
		free(nbr);
		return (nbr_prec);
	}
	return (nbr);
}

int	ft_aligner(char *nbr, t_specs *spec_info)
{
	int	i;
	int	n;

	n = 0;
	if (spec_info->flag_minus)
		n += ft_putstr_count(nbr, spec_info);
	i = 0;
	if (spec_info->negative && spec_info->flag_zero == '0' && ++n)
		ft_putchar('-');
	while (i++ < spec_info->width - ft_strlen(nbr))
	{
		ft_putchar(spec_info->flag_zero);
		n++;
	}
	if (spec_info->negative && spec_info->flag_zero == ' '
		&& !spec_info->flag_minus && ++n)
		ft_putchar('-');
	if (!spec_info->flag_minus)
		n += ft_putstr_count(nbr + spec_info->negative, spec_info);
	free(nbr);
	return (n);
}

int	ft_print_d_i(va_list *arg, t_specs *spec_info)
{
	char	*number;
	int		n;

	n = va_arg(*arg, int);
	if (n == 0 && spec_info->precision == 0 && spec_info->width == 0)
		return (0);
	if (n < 0)
		spec_info->negative = 1;
	number = ft_itoa(n);
	n = 0;
	number = ft_precision(number, spec_info);
	n += ft_aligner(number, spec_info);
	return (n);
}
