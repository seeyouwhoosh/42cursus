# Special targets
.POSIX:
.PHONY: clean re fclean all

# Color
BBLUE		= \033[1;34m
GREEN		= \033[0;32m
NC			= \033[0m

# Compiler
NAME		= harlFilter
CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98
RM			= rm -rf

# Sources
SOURCES		= main.cpp Harl.cpp

# Objects
OBJECTS		= $(SOURCES:.cpp=.o)


# Main program
all: $(OBJECTS) $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Creating $(GREEN)$@$(NC)..."
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) 
	@echo "$(BBLUE)$(NAME)$(NC): $(GREEN)$(NAME)$(NC) created"
	@echo "\033[1;1mOptions available for $(BBLUE)$(NAME)$(NC)\033[1;1m:\nDEBUG\nINFO\nWARNING\nERROR\033[0m"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@$(RM) $(OBJECTS)
	@echo "$(BBLUE)$(NAME)$(NC): Objects cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BBLUE)$(NAME)$(NC): Fully cleaned"

re: fclean all
