# Special targets
.POSIX:
.PHONY: clean re fclean all

# Color
BBLUE		= \033[1;34m
GREEN		= \033[0;32m
NC			= \033[0m

# Compiler
NAME		= fractol
CC			= cc
CFLAGS		= #-Wall -Werror -Wextra
MAKE		= make -sC
RM			= rm -rf
OS			= $(shell uname)

# Libs
LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LINKER		= -L$(LIBFT_DIR) -lft

MLX_DIR 	= include/minilibx
MLX 		= $(MLX_DIR)/libmlx.a

ifeq ($(OS), Linux)
	LINKER	+= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
else
	LINKER	+= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Includes
INCLUDE_DIR	= include
INCLUDES	= -I$(INCLUDE_DIR) \
			  -I$(LIBFT_DIR) \
			  -I$(MLX_DIR)

# Sources
SRC_DIR		= src
SOURCES		= main.c utils.c mandelbrot.c

# Objects
OBJ_DIR		= obj
OBJ			= $(SOURCES:.c=.o)
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))


all: $(LIBFT) $(MLX) $(OBJECTS) $(NAME)

$(LIBFT):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)libft$(NC)..."
	@$(MAKE) $(LIBFT_DIR) bonus
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)libft$(NC) created"

$(MLX):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)minilibx$(NC)..."
	@$(MAKE) $(MLX_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)minilibx$(NC) created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$@$(NC)..."
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME)$(NC) created"


clean:
	@$(MAKE) $(LIBFT_DIR) clean
	@$(MAKE) $(MLX_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): Objects cleaned"

fclean: clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): Fully cleaned"

re: fclean all


