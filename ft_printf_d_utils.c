#include "ft_printf.h"

void ft_print_d(va_list *arg)
{
	ft_putnbr(va_arg(*arg, int));
}