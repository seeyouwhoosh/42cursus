.POSIX:
.PHONY: clean re fclean

NAME = fractol

SOURCES = main.c

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = lib/printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = lib/mlx
MLX = $(MLX_DIR)/libmlx.a

BBLUE = \033[1;34m
NC = \033[0m

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MLX) $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): $(NAME) created"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(MLX_DIR) -c $< -o $@ 

$(FT_PRINTF):
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(FT_PRINTF) created"

$(LIBFT):
	@make bonus -s -C $(LIBFT_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(LIBFT) created"

$(MLX):
	@make -s -C $(MLX_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(MLX) created"

clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(FT_PRINTF_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@rm -f $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Objects cleaned"

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(FT_PRINTF_DIR) fclean
	@rm -f $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): Files cleaned"

re: fclean all


