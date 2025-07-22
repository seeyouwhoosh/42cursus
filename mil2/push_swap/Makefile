.POSIX:
.PHONY: all clean fclean


SOURCES = 

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(SOURCES:.c=.o)

all: NAME

NAME: OBJECTS
	$(CC) $(CFLAGS) $< -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAMES)

re: fclean all