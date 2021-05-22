#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// -- Structs -- //
typedef struct s_format_info
{
	int				flag_minus;
	int				flag_zero;
	int				width;
	int				precision;
	char			type;
}	t_specs;

// -- Main Funcs -- //
int		ft_printf(const char *s, ...);

// -- Utils Funcs -- //
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
void	ft_init_specs(t_specs *spec_info);

// -- Print D -- //
void	ft_print_d(va_list *arg);

// -- Parser Funcs -- //
int		ft_parser(const char *str, t_specs *spec_info, va_list *arg);

#endif
