#include "ft_printf.h"

static int	ft_aligner(unsigned long nbr, int nbr_len, t_specs *spec_info)
{
	int	i;
	int	n;

	n = 0;
	if (spec_info->flag_minus)
		ft_print_hex_nullable(nbr, &n);
	i = 0;
	while (i++ < spec_info->width - nbr_len)
	{
		ft_putchar(' ');
		n++;
	}
	if (!spec_info->flag_minus)
		ft_print_hex_nullable(nbr, &n);
	return (n);
}

int	ft_print_p(va_list *arg, t_specs *spec_info)
{
	unsigned long	number;
	int				n;
	int				number_len;

	n = 0;
	number_len = 0;
	number = va_arg(*arg, unsigned long);
	ft_hexlen_nullable(number, &number_len);
	n += ft_aligner(number, number_len, spec_info);
	return (n);
}
