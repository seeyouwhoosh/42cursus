.POSIX:
.PHONY: re clean fclean tests all

CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = ft_printf.c ft_utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all