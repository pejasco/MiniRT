/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:14:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/06 14:59:24 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//t_argb black = argb(255, 0, 0, 0);


t_canvas create_canvas(t_vars *vars, int width, int height, t_argb rgb)
{
    t_canvas	canvas;
	t_px_coord	coord;
	int			w;
	int			h;

	h = 0;
	canvas.height = height;
	canvas.width = width;
	canvas.rgb = rgb;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			coord = (t_px_coord){.x = (w), .y = (h), .rgb = rgb};
			mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, coord.x, coord.y, (int)rgb);
			//supa_pixel_put(img_vars, coord, rgb);
			w++;
		}
		h++;
	}
	return (canvas);
}
/*
t_canvas create_canvas(t_vars *vars, t_img *img_vars, int width, int height, t_argb rgb)
{
    t_canvas	canvas;
	t_px_coord	coord;
	int			w;
	int			h;

	h = 0;
	canvas.height = height;
	canvas.width = width;
	canvas.rgb = rgb;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			coord = (t_px_coord){.x = (w), .y = (h), .rgb = rgb};
			mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, coord.x, coord.y, (int)rgb);
			//supa_pixel_put(img_vars, coord, rgb);
			w++;
		}
		h++;
	}
	return (canvas);
}
*/

/*
void	supa_pixel_put(t_img *img_vars, t_px_coord coord, t_argb color)
{
	long				offset;

	if (coord.x >= WIDTH || coord.x < 0 || coord.y >= HEIGHT || coord.y < 0)
		return ;
	offset = (img_vars->line_len * coord.y)
		+ (coord.x * (img_vars->bits_per_pixel / 8));
	*((unsigned int *)(offset + img_vars->img_pixels_ptr)) = color;
}
*/

void supa_pixel_put(t_vars *vars, t_px_coord coord, t_argb color) {
    int offset;
    char *pixel;

    if (coord.x >= 0 && coord.x < WIDTH && coord.y >= 0 && coord.y < HEIGHT) {
	offset = (coord.y * vars->img_vars.line_len) + (coord.x * (vars->img_vars.bits_per_pixel / 8));
	pixel = vars->img_vars.img_pixels_ptr + offset;
        *(unsigned int *)pixel = color; // Assuming color is in ARGB format
		put_image_to_window_vars(vars);
    }
}

/*
void	fill_image_with_color(t_img *img_vars, int color)
{
	t_px_coord	point;

	if (!img_vars)
		return ;
	point = (t_px_coord){0};
	while (point.x < WIDTH)
	{
		point.y = 0;
		while (point.y < HEIGHT)
		{
			supa_pixel_put(img_vars, point, color);
			point.y++;
		}
		point.x++;
	}
}
*/
