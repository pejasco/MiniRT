/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:48:40 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/23 14:10:51 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_error_and_delta(int *error, t_delta *delta, t_px_coord *a,
		t_px_coord *b)
{
	delta->x = ft_abs(b->x - a->x);
	delta->y = ft_abs(b->y - a->y);
	*error = 2 * delta->y - delta->x;
}

static void	normalize_coords_bresenham(t_px_coord *a, t_px_coord *b,
		t_slope_status *slope)
{
	if (a->x > b->x)
		px_coord_swap(a, b);
	if ((a->x < b->x) && (a->y > b->y))
	{
		slope->is_negative = true;
		a->y *= -1;
		b->y *= -1;
	}
	else
		slope->is_negative = false;
	if (ft_abs(b->y - a->y) > ft_abs(b->x - a->x))
	{
		slope->is_greater_than_1 = true;
		int_swap(&(a->x), &(a->y));
		int_swap(&(b->x), &(b->y));
	}
	else
		slope->is_greater_than_1 = false;
	if (a->x > b->x)
		px_coord_swap(a, b);
}

static void	draw_pixel_bresenham(t_img *img_vars, t_slope_status slope,
		t_px_coord point)
{
	if (slope.is_greater_than_1 && slope.is_negative)
		supa_pixel_put(img_vars, (t_px_coord){.x = point.y, .y = -point.x},
			point.rgb);
	else if (slope.is_negative)
		supa_pixel_put(img_vars, (t_px_coord){.x = point.x, .y = -point.y},
			point.rgb);
	else if (slope.is_greater_than_1)
		supa_pixel_put(img_vars, (t_px_coord){.x = point.y, .y = point.x},
			point.rgb);
	else
		supa_pixel_put(img_vars, point, point.rgb);
}

static void	draw_colored_pixels_bresenham(t_img *img_vars,
					t_px_coord a,
					t_px_coord b,
					t_slope_status slope)
{
	t_px_coord		current_pix;
	t_interpolation	t;
	int				error;
	t_delta			delta;

	calc_error_and_delta(&error, &delta, &a, &b);
	init_gradient_rgb(&t, &a, &b);
	current_pix = a;
	while (current_pix.x <= b.x)
	{
		current_pix.rgb = gradient_rgb(t.curr, a.rgb, b.rgb);
		draw_pixel_bresenham(img_vars, slope, current_pix);
		if (error > 0)
		{
			current_pix.y++;
			error += 2 * (delta.y - delta.x);
		}
		else
			error += 2 * delta.y;
		current_pix.x++;
		t.curr += t.step;
	}
}

void	draw_line(t_img *img_vars, t_px_coord a, t_px_coord b)
{
	t_slope_status	slope;

	if ((a.x > WIDTH && b.x > WIDTH) || (a.y > HEIGHT && b.y > HEIGHT))
		return ;
	normalize_coords_bresenham(&a, &b, &slope);
	draw_colored_pixels_bresenham(img_vars, a, b, slope);
}
