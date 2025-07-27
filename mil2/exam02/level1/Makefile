.POSIX:
.PHONY: re clean fclean all

CC = cc

NAMES = first_word fizzbuzz	ft_putstr ft_strcpy
SOURCES = $(NAMES:=.c)
OBJECTS = $(SOURCES:.c=.o)

all: 
	# Select one exercise

%: %.c
	$(CC) $< -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAMES)

re: fclean all