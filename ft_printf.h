#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Libs
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// Constants
# define MACOS 1
# define NULL_PTR "0x0\0"
# define NULL_STR "(null)\0"

// Structs
typedef struct s_format_info
{
	int				flag_minus;
	char			flag_zero;
	int				width;
	int				precision;
	char			type;
	int				negative;
}	t_specs;

// Main Funcs
int		ft_printf(const char *s, ...);

// Utils Funcs
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
int		ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(const char *s);
int		ft_intlen(int n);
int		ft_putstr_count(char *str, t_specs *spec_info);
char	*ft_strchr(const char *s, int c);
void	ft_init_specs(t_specs *spec_info);
void	ft_print_adress(unsigned long value, int *counter);
void	ft_print_adress_nullable(unsigned long value, int *counter);
void	ft_adresslen(unsigned long value, int *counter);
void	ft_adresslen_nullable(unsigned long value, int *counter);
char	*ft_itoa_hex(unsigned int value, int upper_case);

// Print Funcs
int		ft_print_d_i(va_list *arg, t_specs *spec_info);
int		ft_print_c(va_list *arg, t_specs *spec_info);
int		ft_print_s(va_list *arg, t_specs *spec_info);
int		ft_print_u(va_list *arg, t_specs *spec_info);
int		ft_print_p(va_list *arg, t_specs *spec_info);
int		ft_print_x_X(va_list *arg, t_specs *spec_info);

// Parser
int		ft_parser(const char *str, t_specs *spec_info, va_list *arg);

// Parser Utils
int	ft_parse_flags(const char *str, t_specs *spec_info);
int	ft_parse_width(const char *str, t_specs *spec_info, va_list *arg);
int	ft_parse_precision(const char *str, t_specs *spec_info, va_list *arg);
int	ft_parse_type(const char *str, t_specs *spec_info);

#endif
