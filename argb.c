/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:31:58 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/22 20:32:43 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
