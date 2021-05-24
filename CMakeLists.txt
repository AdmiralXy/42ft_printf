cmake_minimum_required(VERSION 3.19)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

#add_compile_options(-Wall -Wextra -Werror)

add_executable(ft_printf main.c ft_printf.c ft_printf_d.c ft_printf_utils.c ft_parser.c ft_parser_utils.c ft_atoi.c ft_itoa.c)