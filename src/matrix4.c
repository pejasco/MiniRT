/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:51:46 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/01 14:33:39 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate->scale->translate

#include "../inc/minirt.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

t_matrix_4x4 translate_matrix(double x, double y, double z)
{
	t_matrix_4x4 translate;

	translate = (t_matrix_4x4){
		.entries = {
	{1, 0, 0, x},
	{0, 1, 0, y},
	{0, 0, 1, z},
	{0, 0, 0, 1},
	}};
	return (translate);
}

t_matrix_4x4 scale_matrix(double x, double y, double z)
{
	t_matrix_4x4 translate;

	translate = (t_matrix_4x4){
		.entries = {
	{x, 0, 0, 0},
	{0, y, 0, 0},
	{0, 0, z, 0},
	{0, 0, 0, 1},
	}};
	return (translate);
}

t_matrix_4x4 shear_matrix(t_shear_vars *vars)
{
	t_matrix_4x4 shear;

	shear = (t_matrix_4x4){
		.entries = {
	{1, vars->xy, vars->xz, 0},
	{vars->yx, 1, vars->yz, 0},
	{vars->zx, vars->zy, 1, 0},
	{0, 0, 0, 1},
	}};
	return (shear);
}

