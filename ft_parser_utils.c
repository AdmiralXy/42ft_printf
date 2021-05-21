#include "ft_printf.h"

int	ft_parse_flags(const char *str, t_specs *spec_info)
{
	int n;

	n = 0;
	while (ft_strchr("-0", *str))
	{
		if (*str == '-')
			spec_info->flag = '-';
		else
			spec_info->flag = '0';
	}
	return (n);
}

int ft_parse_width(const char *str, t_specs *spec_info)
{
	int n;

	n = 0;
	return (n);
}

int ft_parse_precision(const char *str, t_specs *spec_info)
{
	int n;

	n = 0;
	return (n);
}

int ft_parse_length(const char *str, t_specs *spec_info)
{
	int n;

	n = 0;
	return (n);
}

int ft_parse_type(const char *str, t_specs *spec_info)
{
	int n;

	n = 0;
	return (n);
}