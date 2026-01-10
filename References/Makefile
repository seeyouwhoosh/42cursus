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
CFLAGS		= -Wall -Werror -Wextra -g
MAKE		= make -sC
RM			= rm -rf
OS			= $(shell uname)

# Libs
LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LINKER		= -L$(LIBFT_DIR) -lft

PRINTF_DIR	= include/printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a
LINKER		+= -L$(PRINTF_DIR) -lftprintf

ifeq ($(OS), Linux)
	MLX_DIR		= include/minilibx_Linux
else
	MLX_DIR 	= include/minilibx_Darwin
endif
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
			  -I$(PRINTF_DIR) \
			  -I$(MLX_DIR)

# Sources
SRC_DIR		= src
SOURCES		= main.c utils.c fractal.c interactions.c

# Objects
OBJ_DIR		= obj
OBJ			= $(SOURCES:.c=.o)
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Bonus sources
BSRC_DIR	= src_bonus
BSOURCES	= 

# Bonus objects
BOBJ_DIR	= obj_bonus
BOBJECTS	= $(addprefix $(BOBJ_DIR)/, $(BSOURCES:.c=.o))


# Libraries and other dependencies
deps: $(LIBFT) $(PRINTF) $(MLX)

$(LIBFT):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)libft$(NC)..."
	@$(MAKE) $(LIBFT_DIR) bonus
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)libft$(NC) created"

$(PRINTF):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)printf$(NC)..."
	@$(MAKE) $(PRINTF_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)printf$(NC) created"

$(MLX):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)minilibx$(NC)..."
	@$(MAKE) $(MLX_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)minilibx$(NC) created"


# Main program
all: deps $(OBJECTS) $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$@$(NC)..."
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME)$(NC) created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 


# Bonus program
bonus: $(BOBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$(NAME) ($@)$(NC)..."
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME) ($@)$(NC) created"

$(BOBJ_DIR)/%.o: $(BOBJ_DIR)/%.c
	@mkdir -p $(BOBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning targets



clean:
	@$(MAKE) $(LIBFT_DIR) clean
	@$(MAKE) $(PRINTF_DIR) clean
	@$(MAKE) $(MLX_DIR) clean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(BOBJ_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): Objects cleaned"

fclean: clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(MAKE) $(PRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): Fully cleaned"

re: fclean all


