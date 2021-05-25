#include "ft_printf.h"

void ft_hexlen(unsigned long value, int *counter)
{
	if (value == 0)
	{
		*counter += 2;
		return;
	}
	value /= 16;
	ft_hexlen(value, counter);
	*counter += 1;
}

void ft_print_hex(unsigned long value, int *counter)
{
	unsigned long	rem;

	if (value == 0)
	{
		*counter += 2;
		ft_putchar('0');
		ft_putchar('x');
		return;
	}
	rem = value % 16;
	value /= 16;
	ft_print_hex(value, counter);

	if (rem > 9)
		ft_putchar((char)(rem - 10 + 'a'));
	else
		ft_putchar('0' + rem);
	*counter += 1;
}

void ft_print_hex_nullable(unsigned long value, int *counter)
{
	if (value == 0)
	{
		*counter += ft_strlen(NULL_PTR);
		ft_putstr(NULL_PTR);
	}
	else
	{
		ft_print_hex(value, counter);
	}
}

void ft_hexlen_nullable(unsigned long value, int *counter)
{
	if (value == 0)
	{
		*counter += ft_strlen(NULL_PTR);
	}
	else
	{
		ft_hexlen(value, counter);
	}
}