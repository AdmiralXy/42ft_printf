NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

INCLUDES = ft_printf.h

SRCS = main.c ft_printf.c ft_printf_d.c ft_printf_utils.c ft_parser.c ft_parser_utils.c ft_atoi.c ft_itoa.c

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

norm:
	norminette $(SRCS)

re: clean all