#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
void	ft_putnbr(int nb);
void	ft_print_d(va_list *arg);
void	ft_putchar(char c);

typedef struct		s_format_info
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			type;
	unsigned char	length;
	int				sign;
	int				tmp;
	int				align;
	int				zr_print;
	int				sp_print;
	int				str_print;
	char			sgn_print;
}					t_format_info;

#endif
