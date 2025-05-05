.POSIX:
.PHONY: re clean fclean tests all

CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = ft_printf.c ft_utils.c
OBJECTS = $(SOURCES:.c=.o)

TEST = test
TEST_SOURCES = test.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

all: $(NAME) $(TEST)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

$(TEST): $(NAME) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJECTS) -L. -lftprintf
	./$@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all