#include "ft_printf.h"

static int	ft_aligner(char c, t_specs *spec_info)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if (spec_info->flag_minus && ++n)
		ft_putchar(c);
	while (i++ < spec_info->width - 1)
	{
		ft_putchar(spec_info->flag_zero);
		n++;
	}
	if (!spec_info->flag_minus && ++n)
		ft_putchar(c);
	return (n);
}

int	ft_print_c(va_list *arg, t_specs *spec_info)
{
	char	c;
	int		n;

	n = 0;
	if (spec_info->type != '%')
		c = (char) va_arg(*arg, int);
	else
		c = '%';
	n += ft_aligner(c, spec_info);
	return (n);
}
