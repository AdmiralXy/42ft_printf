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

int	ft_check_specs(t_specs *spec_info)
{
	int	check_f;
	int	check_s;

	check_f = spec_info->flag_minus || spec_info->width;
	check_s = spec_info->precision != -1 || spec_info->negative;
	if ((check_f || check_s) && spec_info->type == '\0')
		return (0);
	return (1);
}

const char	*ft_put_specificator(const char *str, va_list *arg, int *n, int *e)
{
	int		i;
	t_specs	spec_info;

	i = 0;
	i = ft_parser(++str, &spec_info, arg);
	if (!ft_check_specs(&spec_info))
		*e = 1;
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
	if (spec_info.type == '%')
		*n += ft_print_c(arg, &spec_info);
	return (str + (i - 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;
	int		error;

	if (!format)
		return (-1);
	error = 0;
	n = 0;
	va_start(ap, format);
	while (*format != '\0' && !error)
	{
		if (*format == '%')
			format = ft_put_specificator(format, &ap, &n, &error);
		else
		{
			ft_putchar(*format);
			n++;
		}
		format++;
	}
	va_end(ap);
	if (error)
		return (-1);
	return (n);
}
