/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:14:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/01 14:33:39 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
t_canvas create_canvas(int width, int height)
{
    t_canvas canvas;

    canvas.width = width;
    canvas.height = height;
    return (canvas);
}
*/

void	supa_pixel_put(t_img *img_vars, t_px_coord coord, t_argb color)
{
	long				offset;

	if (coord.x >= WIDTH || coord.x < 0 || coord.y >= HEIGHT || coord.y < 0)
		return ;
	offset = (img_vars->line_len * coord.y)
		+ (coord.x * (img_vars->bits_per_pixel / 8));
	*((unsigned int *)(offset + img_vars->img_pixels_ptr)) = color;
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
