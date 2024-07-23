NAME := minirt
COMMON_FILES := \
	argb.c \
	bresenham.c\
	canvas.c \
	coord_conversion.c \
	event.c \
	key_transform_ops.c \
	matrix_ops.c \
	tran_rotation.c \
	tran_scale.c \
	transform.c \
	tupes.c \
	tupes2.C \
	utilities.c \
	window.c
SRC_DIR := src
OBJ_DIR := build
INC_DIR := inc

FILES := fdf.c $(COMMON_FILES)
SRC := $(addprefix $(SRC_DIR)/, $(FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

FILES_BONUS := fdf.c $(COMMON_FILES)
SRC_BONUS := $(addprefix $(SRC_DIR)/, $(FILES_BONUS))
OBJ_BONUS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))

MLX_INC := lib/minilibx-linux
MLX_STT := lib/minilibx-linux/libmlx.a
FT_INC := lib/libft/inc
FT_STT := lib/libft/lib/libft.a

CFLAGS := -Wall -Wextra -Werror


# -O3 highest optimization
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -I /usr/include -I$(MLX_INC) -I$(FT_INC) -O3 -c $< -o $@ -I$(INC_DIR)

# .SILENT:

all: $(NAME)

$(NAME): $(OBJ) $(MLX_STT) $(FT_STT)
	@rm -f bonus
	$(CC) $(OBJ) $(MLX_STT) $(FT_STT) -I$(MLX_INC) -I$(FT_INC) -l Xext -l X11 -lm -lz -o $@ -I$(INC_DIR)
	@echo "🥰🥰🥰🥰🥰🥰 Complete! 🥰🥰🥰🥰🥰"

bonus: $(OBJ_BONUS) $(MLX_STT) $(FT_STT)
	$(CC) $(OBJ_BONUS) $(MLX_STT) $(FT_STT) -I$(MLX_INC) -I$(FT_INC) -l Xext -l X11 -lm -lz -o $(NAME) -I$(INC_DIR)
	@echo "🥰🥰🥰🥰🥰 Bonus Complete! 🥰🥰🥰🥰🥰"

$(FT_STT):
	$(MAKE) -C lib/libft

$(MLX_STT):
	$(MAKE) -C lib/minilibx-linux all

clean:
	rm -f ./$(OBJ_DIR)/*.o
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/minilibx-linux clean


fclean: clean
	rm -f bonus
	rm -f fdf
	rm -f lib/libft/lib/libft.a
	rm -f lib/libft/lib/*.a

re: fclean all

.PHONY: all, clean, fclean, re