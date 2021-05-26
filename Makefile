NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

INCLUDES = ft_printf.h ft_parser.h

SRCS = ft_printf.c\
		ft_printf_d_i.c\
		ft_printf_s.c\
		ft_printf_c.c\
		ft_printf_u.c\
		ft_printf_p.c\
		ft_printf_p_utils.c\
		ft_printf_x_X.c\
		ft_printf_x_X_utils.c\
		ft_printf_utils.c\
		ft_parser.c\
		ft_parser_utils.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_itoa_u.c

OBJS = ${SRCS:.c=.o}

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUSES)

fclean: clean
	$(RM) $(NAME)

re: clean all