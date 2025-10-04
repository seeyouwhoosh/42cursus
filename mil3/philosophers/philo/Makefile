# Special targets
.POSIX:
.PHONY: clean re fclean all

# Color
BBLUE		= \033[1;34m
GREEN		= \033[0;32m
NC			= \033[0m

# Compiler
NAME		= philo
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
MAKE		= make -sC
RM			= rm -rf

# Libs
LINKER		= -lpthread

# Includes
INCLUDE_DIR	= include
INCLUDES	= -I$(INCLUDE_DIR)

# Sources
SRC_DIR		= src
SOURCES		= main.c utils.c

# Objects
OBJ_DIR		= obj
OBJ			= $(SOURCES:.c=.o)
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Bonus sources
BSRC_DIR	= src
BSOURCES	= 

# Bonus objects
BOBJ_DIR	= obj
BOBJ		= $(BSOURCES:.c=.o)
BOBJECTS	= $(addprefix $(BOBJ_DIR)/, $(BSOURCES:.c=.o))

all: $(OBJECTS) $(NAME)

# Libraries and other dependencies
deps:

# Main program
$(NAME): $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$@$(NC)..."
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME)$(NC) created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

# Bonus program
$(BOBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@mkdir -p $(BOBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

bonus: $(BOBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$(NAME) ($@)$(NC)..."
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJECTS) $(LINKER)
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME) ($@)$(NC) created"

# Cleaning targets
clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(BOBJ_DIR)
	@echo "$(BBLUE)$(NAME)$(NC): Objects cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): Fully cleaned"

re: fclean all


