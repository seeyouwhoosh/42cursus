.POSIX:
.PHONY: all clean fclean re

SOURCES = push_swap.c ft_math.c ft_lists.c sort_ops_a.c sort_ops_b.c sort_ops_both.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = printf
FT_PRINTF = $(FT_PRINTF_DIR)/printf.a

test: $(OBJECTS) $(LIBFT) $(FT_PRINTF) ft_math.o ft_lists.o sort_ops_a.o
	$(CC) $(CFLAGS) ft_math.o ft_lists.o sort_ops_a.o sort_ops_b.o sort_ops_both.o testfunctions.c -Ilibft -Iprintf -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $@

NAME = push_swap
CC = cc
# CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(SOURCES:.c=.o)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@ 

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all