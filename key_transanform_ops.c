/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_transanform_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:46:27 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/22 21:47:41 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mx	create_transl_mtx_hotkey(int key)
{
	t_mx	transl4x4;

	transl4x4
		= (t_mx){.row_num = 4,
		.col_num = 4,
		.entries = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}}};
	if (key == XK_Up)
		transl4x4.entries[1][3] = 10;
	else if (key == XK_Down)
		transl4x4.entries[1][3] = -10;
	else if (key == XK_Left)
		transl4x4.entries[0][3] = -10;
	else if (key == XK_Right)
		transl4x4.entries[0][3] = 10;
	return (transl4x4);
}

t_mx	create_scale_mtx_hotkey(int key_or_button)
{
	t_mx	scale4x4;

	if (key_or_button == XK_i || key_or_button == Button4)
		scale4x4 = create_scale4x4(1.05);
	else if (key_or_button == XK_o || key_or_button == Button5)
		scale4x4 = create_scale4x4(0.95);
	return (scale4x4);
}

t_mx	create_rotate_mtx_hotkey(int key)
{
	t_mx	rotate4x4;

	if (key == XK_e)
		rotate4x4 = rot_y_mx_4x4(1.0 * PI / 180.0);
	else if (key == XK_q)
		rotate4x4 = rot_y_mx_4x4(-1.0 * PI / 180.0);
	else if (key == XK_s)
		rotate4x4 = rot_x_mx_4x4(1.0 * PI / 180.0);
	else if (key == XK_w)
		rotate4x4 = rot_x_mx_4x4(-1.0 * PI / 180.0);
	else if (key == XK_a)
		rotate4x4 = rot_z_mx_4x4(1.0 * PI / 180.0);
	else if (key == XK_d)
		rotate4x4 = rot_z_mx_4x4(-1.0 * PI / 180.0);
	return (rotate4x4);
}

void	transform_all_vertexes(t_vars *vars, t_mx transform)
{
	int	i;
	int	total;

	i = 0;
	total = (vars->map).col_num * (vars->map).row_num;
	while (i < total)
	{
		vars->vertex_arr[i].real_coord = mtxa_mult_mtxb(transform,
				vars->vertex_arr[i].real_coord);
		i++;
	}
}
