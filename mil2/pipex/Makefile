# Special targets
.POSIX:
.PHONY: clean re fclean all

# Color
BBLUE		= \033[1;34m
GREEN		= \033[0;32m
NC			= \033[0m

# Compiler
NAME		= pipex
CC			= cc
CFLAGS		= # -Wall -Werror -Wextra
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

# Includes
INCLUDE_DIR	= include
INCLUDES	= -I$(INCLUDE_DIR) \
			  -I$(LIBFT_DIR) \
			  -I$(PRINTF_DIR) \

# Sources
SRC_DIR		= src
SOURCES		= pipex.c

# Objects
OBJ_DIR		= obj
OBJ			= $(SOURCES:.c=.o)
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))


all: $(LIBFT) $(PRINTF) $(OBJECTS) $(NAME)

$(LIBFT):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)libft$(NC)..."
	@$(MAKE) $(LIBFT_DIR) bonus
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)libft$(NC) created"

$(PRINTF):
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)printf$(NC)..."
	@$(MAKE) $(PRINTF_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)printf$(NC) created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(NAME): $(LIBFT) $(PRINTF) $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$@$(NC)..."
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME)$(NC) created"


clean:
	@$(MAKE) $(LIBFT_DIR) clean
	@$(MAKE) $(PRINTF_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): Objects cleaned"

fclean: clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(MAKE) $(PRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): Fully cleaned"

re: fclean all


