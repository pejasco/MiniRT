#!/bin/sh

# Define the paths to your header files and libraries
HEADER_PATH="/projects/MiniRT/inc/"
LIB_PATH="/projects/MiniRT/lib/libft"

# Compile the code
cc -I$HEADER_PATH -L$LIB_PATH -Werror -Wextra -Wall \
ray.c \
sphere.c \
matrix_inverse.c \
matrix_ops.c \
matrix_other.c \
matrix_other2.c \
matrix_rotate.c \
test.c \
tupes.c \
tupes2.c \
window.c -g -lm -o diu