#include "ft_printf.h"

void	ft_print_specs(t_specs *spec_info)
{
	printf("\nflag_minus: %d\n", spec_info->flag_minus);
	printf("flag_zero: %d\n", spec_info->flag_zero);
	printf("width: %d\n", spec_info->width);
	printf("precision: %d\n", spec_info->precision);
	printf("type: %c\n", spec_info->type);
}

const char	*ft_put_specificator(const char *str, va_list *arg)
{
	int n;

	n = 0;
	t_specs spec_info;
	n = ft_parser(++str, &spec_info, arg);
	if (spec_info.type == 'd')
		ft_print_d(arg);
	if (*str == 'c')
		ft_putchar(va_arg(*arg, int));
	return (str + n);
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