#ifndef FT_PARSER_H
# define FT_PARSER_H

int	ft_parse_flags(const char *str, t_specs *spec_info);
int ft_parse_width(const char *str, t_specs *spec_info);
int ft_parse_precision(const char *str, t_specs *spec_info);
int ft_parse_length(const char *str, t_specs *spec_info);
int ft_parse_type(const char *str, t_specs *spec_info);

#endif
