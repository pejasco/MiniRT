/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:22:41 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/20 19:22:58 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	iso_kb_key(int key, t_vars *vars)
{
	printf("%d pressed\n", key);
	if (key == XK_Escape)
		mlx_loop_end(vars->mlx_ptr);
	else if (key == XK_Left || key == XK_Right || key == XK_Up
		|| key == XK_Down)
		translate(vars, key);
	else if (key == XK_i || key == XK_o || key == Button4 || key == Button5)
		scale(vars, key);
	else if (key == XK_q || key == XK_e || key == XK_w || key == XK_s
		|| key == XK_a || key == XK_d)
		rotate(vars, key);
	return (0);
}

int	iso_mouse_button(int button, int x, int y, t_vars *vars)
{
	x += 0;
	y += 0;
	printf("%d pressed\n", button);
	if (button == Button4 || button == Button5)
		scale(vars, button);
	return (0);
}