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
MLX_DIR		= include/minilibx_Linux
MLX 		= $(MLX_DIR)/libmlx.a
LINKER	+= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Includes
INCLUDE_DIR	= include
INCLUDES	= -I$(INCLUDE_DIR) \
			  -I$(MLX_DIR)

# Sources
SRC_DIR		= src
SOURCES		= main.c utils.c fractal.c libft_utils.c ft_strtod.c

# Objects
OBJ_DIR		= obj
OBJ			= $(SOURCES:.c=.o)
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Bonus sources
BSRC_DIR	= src_bonus
BSOURCES	= main.c utils.c fractal.c libft_utils.c ft_strtod.c interactions.c 

# Bonus objects
BOBJ_DIR	= obj_bonus
BOBJECTS	= $(addprefix $(BOBJ_DIR)/, $(BSOURCES:.c=.o))


all:  $(NAME)


# Libraries and other dependencies
deps: $(MLX)

$(MLX):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)minilibx$(NC)..."
	@$(MAKE) $(MLX_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)minilibx$(NC) created"


# Main program
$(NAME): deps $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$@$(NC)..."
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME)$(NC) created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 


# Bonus program
bonus: $(BOBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$(NAME) ($@)$(NC)..."
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME) ($@)$(NC) created"

$(BOBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@mkdir -p $(BOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Cleaning targets

clean:
	@$(MAKE) $(MLX_DIR) clean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(BOBJ_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): Objects cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): Fully cleaned"

re: fclean all


