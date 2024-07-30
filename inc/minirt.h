/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:46:52 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/30 23:28:43 by chuleung         ###   ########.fr       */
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
#include <stdbool.h>

#define EPSILON 0.00001
#define WIDTH 1920
#define HEIGHT 1080
#define MAX_COL 4
#define MAX_ROW 4
# define WHITE 0xffffff
# define BLACK 0x000000
# define PI 3.1415926
# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KYEL "\x1B[33m"

typedef int	t_argb;

typedef struct s_atof_vars
{
    double  result; //0.0
    int     exponent; //0
    double  sign; //1.0
    int     exponent_sign; //1
    double  fraction; //0.1
} t_atof_vars;

typedef enum e_tuple_type
{
	Vector,
	Point,
} t_tuple_type;


//______________________________________
//struc for bresenham:

typedef struct s_slope_status
{
	bool	is_greater_than_1;
	bool	is_negative;
}	t_slope_status;

typedef struct s_interpolation
{
	double	curr;
	double	step;
}	t_interpolation;

typedef struct s_delta
{
	int	x;
	int	y;
}	t_delta;

//______________________________________

typedef struct s_px_coord
{
	int		x;
	int		y;
	int		rgb;
}	t_px_coord;

/*
typedef struct s_matrix
{
	int			row_num;
	int			col_num;
	double		entries[MAX_ROW][MAX_COL];
}	t_mx;
*/

typedef struct s_matrix_4x4
{
	double entries[4][4];
} t_matrix_4x4;

typedef struct s_submatrix_vars
{
	t_matrix_4x4	smtx;
	int				sub_row;
	int				sub_col;
	int				row;
	int				col;
} t_submatrix_vars;

typedef	struct s_determinant_vars
{
	double	cofactor_row_0_x_col_0;
	double	cofactor_row_0_x_col_1;
	double	cofactor_row_0_x_col_2;
	double 	cofactor_row_0_x_col_3;
	double	determinant;
} t_determinant_vars;

typedef struct s_shear_vars
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
} t_shear_vars;

typedef struct s_ray
{
	t_tuple point;
	t_tuple vector;
} t_ray;

/*
int main(void)
{
	t_matrix_4X4 haha;

	haha = (t_matrix_4X4){
		.entries = {
	{1, 2, 3, 4},
	{5.5, 6.5, 7.5, 8.5},
	{9, 10, 11, 12},
	{13.5, 14.5, 15.5, 16.5},
	}};
	
	assert(haha.entries[0][0] == 1);
	assert(haha.entries[1][2] == 7.5);
	printf("diuuuuuuuuuuuuuuuuuu\n");
	assert(haha.entries[3][2] == 999);
	assert(haha.entries[3][3] == 16.5);
	return (0);
}
*/

typedef struct s_tuple
{
	double			x;
	double			y;
	double			z;
	double			w;
	t_tuple_type 	type;
	int				rgb;
	//t_mx			real_coord;
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

/*
typedef struct s_map
{
	int			col_num;
	int			row_num;
}	t_map;
*/

typedef struct s_vars //(before: s_mlx_data)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img_vars;
	//t_vertex	*vertex_arr;
	//t_map	map;
}	t_vars;


//argc.c
t_argb	argb(unsigned char alpha, unsigned char r, unsigned char g,
				unsigned char b);
unsigned char	get_a(t_argb argb);
unsigned char	get_r(t_argb argb);
unsigned char	get_g(t_argb argb);
unsigned char	get_b(t_argb argb);

//bresenham.c
//void	draw_line(t_img *img_vars, t_px_coord a, t_px_coord b);

//canvas.c
void	supa_pixel_put(t_img *img_vars, t_px_coord coord, t_argb color);

//color.c
t_color create_color(double r, double g, double b);
t_color add_colors(const t_color *a, const t_color *b);
t_color subtract_colors(const t_color *original, const t_color *subtract);
t_color multiply_colors(const t_color *a, const t_color *b);

//cocord_conversion.c
/*
t_mx	pxcoord_to_mx(t_px_coord px_coord);
t_px_coord	mx_to_pxcoord(t_mx mx);
t_px_coord	raster_coord(t_mx screen_coord);
*/

//event.c
int	iso_kb_key(int key, t_vars *vars);
int	iso_mouse_button(int button, int x, int y, t_vars *vars);

/*
//key_transl_ops
t_mx	create_transl_mtx_hotkey(int key);
t_mx	create_scale_mtx_hotkey(int key_or_button);
t_mx	create_rotate_mtx_hotkey(int key);
//void	transform_all_vertexes(t_vars *vars, t_mx transform);

//matrix_ops
void	multi_process(t_mx *product, t_mx *mxa, t_mx *mxb);
void	mx_mult_error_msg(void);
t_mx	mtxa_mult_mtxb(t_mx mtxa, t_mx mtxb);

//tran_rotation
t_mx	rot_x_mx_4x4(double degree);
t_mx	rot_y_mx_4x4(double degree);
t_mx	rot_z_mx_4x4(double degree);

//tran_scale
t_mx	create_scale4x4(double scale);
*/

//tranform
/*
t_mx	mx_iso4x4(void);
void	translate(t_vars *vars, int key);
void	scale(t_vars *vars, int key);
void	rotate(t_vars *vars, int key);
*/

//tupes
t_tuple	create_tuples(double x, double y, double z,
				double w, t_tuple_type type);
t_tuple	add_tuples(const t_tuple *a, const t_tuple *b);
t_tuple	substract_tuples(const t_tuple *a, const t_tuple *b);
t_tuple	negate_tuple(const t_tuple *a);
t_tuple scale_tuple(const t_tuple *a, double scale);

//tupes
double	find_magnitude(const t_tuple *a);
t_tuple	normalize_vector(const t_tuple *a, double magnitude);
double	dot_product(const t_tuple *a, const t_tuple *b);
t_tuple	cross_product(const t_tuple *a, const t_tuple *b);

//matrix
bool			are_the_same_matrix(const t_matrix_4x4 *a,
					const t_matrix_4x4 *b);
t_matrix_4x4	multiply_matrices(const t_matrix_4x4 *a,
					const t_matrix_4x4 *b);
t_matrix_4x4	transpose_a_matrix(const t_matrix_4x4 *mtx);
void			print_matrix(t_matrix_4x4 *mtx);

//matrix2
t_matrix_4x4	create_matrix_filled_with_zero(void);
t_matrix_4x4	find_submatrix(t_matrix_4x4 *mtx, int omit_row,
					int omit_col, int smtx_dimen);
double 			calculate_cofactor(t_matrix_4x4 *mtx, int omit_row,
					int omit_col, int size);
double			calculate_determinant(t_matrix_4x4 *mtx, int size);
double 			calculate_minor(t_matrix_4x4 *mtx, int omit_row,
					int omit_col, int size);

//matrix3
bool			is_invertible(t_matrix_4x4 *mtx, int size);
t_matrix_4x4	process_a_cofactor_matrix(t_matrix_4x4 *mtx, int size);
t_matrix_4x4	inverse_a_matrix(t_matrix_4x4 *mtx, int size);

//matrix4
t_matrix_4x4	translate_matrix(double x, double y, double z);
t_matrix_4x4	scale_matrix(double x, double y, double z);
t_matrix_4x4	shear_matrix(t_shear_vars *vars);

//matrix5
double			get_radian(double degree);
t_matrix_4x4	rotate_x_matrix(double radian);
t_matrix_4x4	rotate_y_matrix(double radian);
t_matrix_4x4	rotate_z_matrix(double radian);

//utilities
void	px_coord_swap(t_px_coord *a, t_px_coord *b);
int		round_double(double n);
int		ft_abs(int nbr);
bool	equal(double a, double b);

//utilities2
void	print_matrix(t_matrix_4x4 *mtx);

//window
void 	set_up_hooks(t_vars *vars);
void	window_handle(t_vars *vars);
void	window_close(t_vars *vars);

#endif