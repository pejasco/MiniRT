/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:31:58 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/04 19:23:57 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"



//0 is usually mean full transparency 255 mean full opacity (opaque)
t_argb	argb(unsigned char alpha, unsigned char r, unsigned char g,
				unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, alpha});
}

unsigned char	get_a(t_argb argb)
{
	return (((unsigned char *)&argb)[3]);
}

unsigned char	get_r(t_argb argb)
{
	return (((unsigned char *)&argb)[2]);
}

unsigned char	get_g(t_argb argb)
{
	return (((unsigned char *)&argb)[1]);
}

unsigned char	get_b(t_argb argb)
{
	return (((unsigned char *)&argb)[0]);
}

t_argb add_argb(t_argb color_1, t_argb color_2)
{
	t_argb result;
	result = argb(0x00,
			get_r(color_1) + get_r(color_2),
			get_g(color_1) + get_g(color_2),
			get_b(color_1) + get_b(color_2));
	return (result);
}

t_argb subtract_argb(t_argb color_1, t_argb color_2)
{
	t_argb result;
	result = argb(0x00,
			get_r(color_1) - get_r(color_2),
			get_g(color_1) - get_g(color_2),
			get_b(color_1) - get_b(color_2));
	return (result);
}

t_argb scale_argb(t_argb color_1, double scale)
{
	t_argb result;
	result = argb(0x00,
			get_r(color_1) * scale,
			get_g(color_1) * scale,
			get_b(color_1) * scale);
	return (result);
}

t_argb multiply_argb(t_argb color_1, t_argb color_2)
{
	t_argb result;
	result = argb(0x00,
			get_r(color_1) * get_r(color_2),
			get_g(color_1) * get_g(color_2),
			get_b(color_1) * get_b(color_2));
	return (result);
}
