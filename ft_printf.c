#include "ft_printf.h"

void	ft_print_specs(t_specs *spec_info)
{
	printf("\nflag_minus: %d\n", spec_info->flag_minus);
	printf("flag_zero: %d\n", spec_info->flag_zero);
	printf("width: %d\n", spec_info->width);
	printf("precision: %d\n", spec_info->precision);
	printf("type: %c\n", spec_info->type);
}

void	ft_fix_specs(t_specs *spec_info)
{
	if (spec_info->flag_minus && spec_info->flag_zero)
		spec_info->flag_zero = 0;
	if (spec_info->precision && spec_info->flag_zero)
		spec_info->flag_zero = 0;
}

const char	*ft_put_specificator(const char *str, va_list *arg)
{
	int n;

	n = 0;
	t_specs spec_info;
	n = ft_parser(++str, &spec_info, arg);
	ft_fix_specs(&spec_info);
	if (spec_info.type == 'd')
		ft_print_d(arg, &spec_info);
	if (*str == 'c')
		ft_putchar(va_arg(*arg, int));
	return (str + (n - 1));
}

int	ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			format = ft_put_specificator(format, &ap);
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (1);
}