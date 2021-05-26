#include "ft_printf.h"

void	ft_fix_specs(t_specs *spec_info)
{
	if (spec_info->flag_minus && spec_info->flag_zero)
		spec_info->flag_zero = ' ';
	if (spec_info->precision > 0 && spec_info->flag_zero)
		spec_info->flag_zero = ' ';
	if (spec_info->precision == 0 && spec_info->flag_zero)
		spec_info->flag_zero = ' ';
}

const char	*ft_put_specificator(const char *str, va_list *arg, int *n)
{
	int		i;
	t_specs	spec_info;

	i = 0;
	i = ft_parser(++str, &spec_info, arg);
	ft_fix_specs(&spec_info);
	if (spec_info.type == 'd' || spec_info.type == 'i')
		*n += ft_print_d_i(arg, &spec_info);
	if (spec_info.type == 'u')
		*n += ft_print_u(arg, &spec_info);
	if (spec_info.type == 'c')
		*n += ft_print_c(arg, &spec_info);
	if (spec_info.type == 's')
		*n += ft_print_s(arg, &spec_info);
	if (spec_info.type == 'p')
		*n += ft_print_p(arg, &spec_info);
	if (spec_info.type == 'x' || spec_info.type == 'X')
		*n += ft_print_x_X(arg, &spec_info);
	if (spec_info.type == '%' && ++*n)
		ft_putchar('%');
	return (str + (i - 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;

	n = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			format = ft_put_specificator(format, &ap, &n);
		else
		{
			ft_putchar(*format);
			n++;
		}
		format++;
	}
	va_end(ap);
	return (n);
}
