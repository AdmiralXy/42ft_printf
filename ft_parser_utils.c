#include "ft_printf.h"

void	ft_init_specs(t_specs *spec_info)
{
	spec_info->flag_minus = 0;
	spec_info->flag_zero = ' ';
	spec_info->width = 0;
	spec_info->precision = -1;
	spec_info->type = '\0';
	spec_info->negative = 0;
}

int	ft_parse_flags(const char *str, t_specs *spec_info)
{
	int	n;

	n = 0;
	while (ft_strchr("-0", *str))
	{
		if (*str == '-')
			spec_info->flag_minus = 1;
		else if (*str == '0')
			spec_info->flag_zero = '0';
		str++;
		n++;
	}
	return (n);
}

int	ft_parse_width(const char *str, t_specs *spec_info, va_list *arg)
{
	int	tmp;
	int	n;

	n = 0;
	if (*str == '*')
	{
		tmp = va_arg(*arg, int);
		if (tmp < 0)
		{
			spec_info->width = -tmp;
			spec_info->flag_minus = 1;
		}
		else
			spec_info->width = tmp;
		n++;
	}
	else
	{
		spec_info->width = ft_atoi(str);
		tmp = spec_info->width;
		while (tmp && ++n)
			tmp /= 10;
	}
	return (n);
}

int	ft_parse_precision(const char *str, t_specs *spec_info, va_list *arg)
{
	int	n;
	int	number;

	n = 0;
	if (*str == '.' && str++)
	{
		spec_info->precision = 0;
		n++;
		if (*str == '*' && n++)
			spec_info->precision = va_arg(*arg, int);
		else if (ft_strchr("0123456789", *str))
		{
			while (*str == '0' && n++)
				str++;
			spec_info->precision = ft_atoi(str);
			number = spec_info->precision;
			while (number > 0)
			{
				number /= 10;
				n++;
			}
		}
	}
	return (n);
}

int	ft_parse_type(const char *str, t_specs *spec_info)
{
	if (ft_strchr("cspdiuxX%", *str))
		spec_info->type = *str;
	return (1);
}
