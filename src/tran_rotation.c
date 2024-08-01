/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tran_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:58:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/01 14:33:39 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_mx	rot_x_mx_4x4(double degree)
{
	t_mx	rot_x;

	rot_x = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{1, 0, 0, 0},
	{0, cos(degree), -sin(degree), 0},
	{0, sin(degree), cos(degree), 0},
	{0, 0, 0, 1}}};
	return (rot_x);
}

t_mx	rot_y_mx_4x4(double degree)
{
	t_mx	rot_y;

	rot_y = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{cos(degree), 0, sin(degree), 0},
	{0, 1, 0, 0},
	{-sin(degree), 0, cos(degree), 0},
	{0, 0, 0, 1}}};
	return (rot_y);
}

t_mx	rot_z_mx_4x4(double degree)
{
	t_mx	rot_z;

	rot_z = (t_mx){
		.row_num = 4,
		.col_num = 4,
		.entries = {
	{cos(degree), -sin(degree), 0, 0},
	{sin(degree), cos(degree), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}}};
	return (rot_z);
}