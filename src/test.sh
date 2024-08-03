#!/bin/sh

# Define the paths to your header files and libraries
HEADER_PATH="projects/MiniRT/inc/"
MINILIBX_PATH="../lib/minilibx-linux/"


# Compile the code
cc -I$HEADER_PATH -L$MINILIBX_PATH -Werror -Wextra -Wall \
window.c \
event.c \
test.c \
ray.c \
sphere.c \
matrix_inverse.c \
matrix_ops.c \
matrix_other.c \
matrix_other2.c \
matrix_rotate.c \
tupes.c \
tupes2.c -lXext -lX11 -lm -lmlx_Linux -o diu



#tupes2.c -lm -lmlx_Linux -lX11 -lXext -o diu