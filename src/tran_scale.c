/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tran_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:00:15 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/22 23:43:31 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mx	create_scale4x4(double scale)
{
	t_mx	scale4x4;

	scale4x4 = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{scale, 0, 0, 0},
	{0, scale, 0, 0},
	{0, 0, scale, 0},
	{0, 0, 0, 1}}};
	return (scale4x4);
}