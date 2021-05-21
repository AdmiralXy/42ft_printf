#include "ft_printf.h"

const char	*ft_put_specificator(const char *str, va_list *arg)
{
	t_specs spec_info;
	ft_parser(++str, &spec_info);
	if (*str == 'd')
		ft_print_d(arg++);
	if (*str == 'c')
		ft_putchar(va_arg(*arg, int));
	return (str);
}

int	ft_printf(const char *format, ...)
{
	int i;
	va_list ap;

	i = 0;
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