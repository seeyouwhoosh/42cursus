.POSIX:
.PHONY: all clean fclean re

NAME = push_swap
BNAME = checker

MAIN = push_swap.c 
BMAIN = checker.c

SOURCES = ft_math.c ft_lists.c sort_ops_a.c sort_ops_b.c sort_ops_both.c calc_costs.c ft_moves.c main_utils.c lsts_sort_ops.c
BSOURCES = 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = printf
FT_PRINTF = $(FT_PRINTF_DIR)/printf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(SOURCES:.c=.o) $(MAIN:.c=.o)
BOBJECTS = $(SOURCES:.c=.o) $(BSOURCES:.c=.o) $(BMAIN:.c=.o)

all: $(NAME)

bonus: $(LIBFT) $(FT_PRINTF) $(BOBJECTS)
	$(CC) $(CFLAGS) $(BOBJECTS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(BNAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@ 

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME) $(BNAME)

re: fclean all