NAME = miniRT
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MLX_DIR = mlx
LIBFT_DIR = libft
INCLUDE_DIR	= includes
GNL_DIR = gnl
INCLUDES	= -I$(INCLUDE_DIR) \
			  -I$(MLX_DIR) \
			  -I$(LIBFT_DIR) \

SRC = main.c free_file.c utils.c error_file.c append.c start.c\
	init/init_file.c init/init_vecs.c\
	parse/parse_ambient_light.c parse/parse_light.c parse/parse_sphere.c parse/parse_cylinder.c parse/parse_camera.c parse/parse_plane.c parse/parse1.c \
	ask/ask.c ask/ask2.c \
	move/move1.c move/move2.c move/move3.c \
	resize/resize.c resize/resize2.c resize/resize3.c \
	math/base_change.c math/cross_product.c math/rotate.c math/rotate_base.c \
	rotate/rotate.c rotate/rotate2.c \
	interface/hooks.c interface/key_hook.c interface/mouse.c interface/obj_move.c interface/obj_move2.c\
	main_loop/loop.c main_loop/intersect.c main_loop/paint.c main_loop/paint2.c 

OBJ_DIR = objs

OBJS = $(SRC:.c=.o)
OBJECTS	= $(addprefix $(OBJ_DIR)/, $(OBJS))

OBJS_BONUS = $(SRC_BONUS:.c=.o)

ifeq ($(shell uname), Darwin)
	MLX_DIR = mlx_mac
	MLXFLAGS = -L$(MLX_DIR) -Llibft -lmlx -lft -framework OpenGL -framework AppKit
else
	MLXFLAGS = -Lmlx -lmlx -lX11 -lXext -lm -lbsd -lft -Llibft
endif

MLX = $(MLX_DIR)/libmlx.a
LIBFT = libft/libft.a

objs/%.o: srcs/%.c
	@mkdir -p objs objs/ask objs/hooks objs/init objs/interface objs/main_loop objs/math objs/move objs/parse objs/resize objs/rotate
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) -o $@ 

$(MLX):
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C libft

all: $(NAME) 

$(NAME_BONUS): $(MLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) -o $@

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJECTS) $(OBJS_BONUS)

fclean: clean
	rm -rf objs
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C libft

re: fclean all
