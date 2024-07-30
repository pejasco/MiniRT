/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:54:54 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/30 18:23:58 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate->scale->translate

#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double get_radian(double degree)
{
	return (degree /180 *PI);
}
2
t_matrix_4x4 rotate_x_matrix(double radian)
{
	t_matrix_4x4 rotate;

	rotate = (t_matrix_4x4){
		.entries = {
	{1, 0, 0, 0},
	{0, cos(radian), -sin(radian), 0},
	{0, sin(radian), cos(radian), 0},
	{0, 0, 0, 1},
	}};
	return (rotate);
}

t_matrix_4x4 rotate_y_matrix(double radian)
{
	t_matrix_4x4 rotate;

	rotate = (t_matrix_4x4){
		.entries = {
	{cos(radian), 0, sin(radian), 0},
	{0, 1, 0, 0},
	{-sin(radian), 0, cos(radian), 0},
	{0, 0, 0, 1},
	}};
	return (rotate);
}

t_matrix_4x4 rotate_z_matrix(double radian)
{
	t_matrix_4x4 rotate;

	rotate = (t_matrix_4x4){
		.entries = {
	{cos(radian), -sin(radian), 0, 0},
	{sin(radian), cos(radian), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	}};
	return (rotate);
}
