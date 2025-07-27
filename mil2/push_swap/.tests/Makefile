.POSIX:
.PHONY: all clean fclean re


SOURCES = program_dump.c

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all