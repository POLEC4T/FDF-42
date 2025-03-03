SRC_DIR=src
INC_DIR=include
OBJ_DIR=.obj
MLX_DIR=mlx_linux
LIBFT_DIR=libft

CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR)

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/map_parsing.c \
		$(SRC_DIR)/frees.c \
		$(SRC_DIR)/frees2.c \
		$(SRC_DIR)/3d_rotates.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/utils_color.c \
		$(SRC_DIR)/utils_exit.c \
		$(SRC_DIR)/utils_exit2.c \
		$(SRC_DIR)/utils_str.c \
		$(SRC_DIR)/bresenham.c \
		$(SRC_DIR)/my_mlx.c \
		$(SRC_DIR)/display.c \
		$(SRC_DIR)/init_map.c \
		$(SRC_DIR)/init_map2.c


OBJS = ${SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

NAME=fdf

all: libs $(NAME)

libs:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -I$(MLX_DIR) -lXext -lX11 -lm $(LIBFT_DIR)/libft.a -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/fdf.h Makefile $(LIBFT_DIR)/libft.a | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: 
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR) $(NAME)

re : fclean all

.PHONY : all clean fclean re