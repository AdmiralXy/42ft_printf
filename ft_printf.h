#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// -- Structs -- //
typedef struct s_format_info
{
	unsigned char	flag;
	int				width;
	int				precision;
	char			type;
	unsigned char	length;
}	t_specs;

// -- Main Funcs -- //
int		ft_printf(const char *s, ...);

// -- Utils Funcs -- //
void	ft_putnbr(int nb);
void	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
void	ft_init_specs(t_specs *spec_info);

// -- Print D -- //
void	ft_print_d(va_list *arg);

// -- Parser Funcs -- //
int		ft_parser(const char *str, t_specs *spec_info);

#endif
