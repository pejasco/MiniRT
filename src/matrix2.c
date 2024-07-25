/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:06:19 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/25 20:49:17 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_matrix_4x4
{
	double entries[4][4];
} t_matrix_4x4;

typedef struct s_submatrix_vars
{
	t_matrix_4x4	smtx;
	int				sub_row;
	int				sub_col;
	int				row;
	int				col;
} t_submatrix_vars;


void print_matrix(t_matrix_4x4 *mtx)
{
    printf("#########################################################\n");
    printf("{%f, %f, %f, %f}\n", mtx->entries[0][0],
        mtx->entries[0][1], mtx->entries[0][2], mtx->entries[0][3]);
    printf("{%f, %f, %f, %f}\n", mtx->entries[1][0],
        mtx->entries[1][1], mtx->entries[1][2], mtx->entries[1][3]);
    printf("{%f, %f, %f, %f}\n", mtx->entries[2][0],
        mtx->entries[2][1], mtx->entries[2][2], mtx->entries[2][3]);
    printf("{%f, %f, %f, %f}\n", mtx->entries[3][0],
        mtx->entries[3][1], mtx->entries[3][2], mtx->entries[3][3]);
    printf("#########################################################\n");
}

t_matrix_4x4	create_matrix_filled_with_zero(void)
{
	t_matrix_4x4	mtx_with_zero;

	mtx_with_zero = (t_matrix_4x4){
		.entries = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	}};
	return (mtx_with_zero);
}

double	determinant_matrix_(t_matrix_4x4 *mtx)
{
	double	result;

	result = (mtx->entries[0][0] * mtx->entries[1][1]
			- mtx->entries[0][1] * mtx->entries[1][0]);
	return (result);
}

t_matrix_4x4	find_submatrix(t_matrix_4x4 *mtx, int omit_row,
					int omit_col, int smtx_dimen)
{
	t_submatrix_vars	smtx_vars;

	smtx_vars.sub_row = 0;
	smtx_vars.row = 0;
	smtx_vars.smtx = create_matrix_filled_with_zero();
	while (smtx_vars.sub_row < smtx_dimen && smtx_vars.row < (smtx_dimen + 1))
	{
		smtx_vars.sub_col = 0;
		smtx_vars.col = 0;
		if (smtx_vars.row == omit_row)
			++smtx_vars.row;
		while (smtx_vars.sub_col < smtx_dimen
			&& smtx_vars.col < (smtx_dimen + 1))
		{
			if (smtx_vars.col == omit_col)
				++smtx_vars.col;
			smtx_vars.smtx.entries[smtx_vars.sub_row][smtx_vars.sub_col]
				= mtx->entries[smtx_vars.row][smtx_vars.col];
			++smtx_vars.col;
			++smtx_vars.sub_col;
		}
		++smtx_vars.row;
		++smtx_vars.sub_row;
	}
	return (smtx_vars.smtx);
}

int	main(void)
{
	t_matrix_4x4	test;
	t_matrix_4x4	result;

	test = (t_matrix_4x4){
		.entries = {
	{-6, 1, 1, 6},
	{-8, 5, 8, 6},
	{-1, 0, 8, 2},
	{-7, 1, -1, 1},
	}};
	result = find_submatrix(&test, 2, 1, 3);
	print_matrix(&result);
	return (0);
}
















/*
t_matrix_4x4	matrix_multiply_identity(const t_matrix_4x4 *mtx)
{
	t_matrix_4x4	result;
	t_matrix_4x4	identity;

	identity = (t_matrix_4x4){
			.entries = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1},
		}};
	result = multiply_matrices(mtx, &identity);
	return (result);
}
*/