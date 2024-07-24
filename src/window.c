/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:30:38 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/23 22:35:57 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void set_up_hooks(t_vars *vars)
{
	mlx_hook(vars->win_ptr, KeyPress, KeyPressMask, iso_kb_key, vars);
	mlx_mouse_hook(vars->win_ptr, iso_mouse_button, vars);
}

void	window_handle(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window
		(vars->mlx_ptr, WIDTH, HEIGHT, "!!! miniRT !!!");
	vars->img_vars.img_ptr = mlx_new_image(vars->mlx_ptr, WIDTH, HEIGHT);
	vars->img_vars.img_pixels_ptr = mlx_get_data_addr(vars->img_vars.img_ptr,
			&vars->img_vars.bits_per_pixel,
			&vars->img_vars.line_len,
			&vars->img_vars.endian);
}

void	put_image_to_window_vars(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, vars->img_vars.img_ptr, 0, 0);
}

void	window_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->img_vars.img_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
}
