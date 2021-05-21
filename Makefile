NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

INCLUDES = ft_printf.h

SRCS = ft_printf.c

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