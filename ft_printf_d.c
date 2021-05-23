#include "ft_printf.h"

char	*ft_precision(char *nbr, int precision)
{
	char	*nbr_w_prec;
	int		nbr_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nbr_len = ft_strlen(nbr);
	if (precision > nbr_len)
	{
		nbr_w_prec = malloc(sizeof(char) * (precision + 1));
		while (i < precision - nbr_len)
			nbr_w_prec[i++] = '0';
		while (i < precision)
		{
			nbr_w_prec[i] = nbr[j];
			i++;
			j++;
		}
		nbr_w_prec[i] = '\0';
		free(nbr);
		return (nbr_w_prec);
	}
	return (nbr);
}

int	ft_aligner(char *nbr, int width, int direction, char filler)
{
	int	i;
	int n;

	n = 0;
	if (direction == 1)
		ft_putstr(nbr);
	i = 0;
	if (filler)
		filler = '0';
	else
		filler = ' ';
	while (i < width - ft_strlen(nbr))
	{
		ft_putchar(filler);
		n++;
		i++;
	}
	if (direction == -1)
		ft_putstr(nbr);
	free(nbr);
	return (n);
}

int	ft_print_d(va_list *arg, t_specs *spec_info)
{
	char	*number;

	number = ft_itoa(va_arg(*arg, int));
	number = ft_precision(number, spec_info->precision);
	if (spec_info->width > ft_strlen(number))
	{
		if (spec_info->flag_minus)
			ft_aligner(number, spec_info->width, 1, spec_info->flag_zero);
		else
			ft_aligner(number, spec_info->width, -1, spec_info->flag_zero);
	}
	else
		ft_aligner(number, 0, 1, spec_info->flag_zero);
}
