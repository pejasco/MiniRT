/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:46:52 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/21 18:23:37 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>

#define EPSILON 0.00001
#define WIDTH 1920
#define HEIGHT 1080

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	t_tuple_type type;
	//int         rgb;
} t_tuple;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
} t_color;

typedef struct s_img
{
	void	*img_ptr; //ptr to mlx_new_image
	char	*img_pixels_ptr; //ptr to the pixels of a image
	int		bits_per_pixel; //8 * 4bytes    1 pixel = 4 bits = 32
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_map
{
	int	col_num;
	int	row_num;
}	t_map;

typedef struct s_vars //(before: s_mlx_data)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img_vars;
	t_map	map;
}	t_vars;

typedef struct s_canvas
{
	int	width;
	int	height;
} t_canvas;

typedef enum e_tuple_type
{
	Vector,
	Point,
} t_tuple_type;

int	equal(double a, double b);

#endif