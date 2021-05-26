#include "ft_printf.h"

int	ft_parser(const char *str, t_specs *spec_info, va_list *arg)
{
	int	n;

	n = 0;
	ft_init_specs(spec_info);
	n += ft_parse_flags(str + n, spec_info);
	n += ft_parse_width(str + n, spec_info, arg);
	n += ft_parse_precision(str + n, spec_info, arg);
	n += ft_parse_type(str + n, spec_info);
	return (n);
}
