/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:42:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/28 21:28:17 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//ddterminant > minor > cofactor

typedef struct s_matrix_4x4
{
	double entries[4][4];
} t_matrix_4x4;

double calculate_minor(t_matrix_4x4 *mtx, int omit_row, int omit_col, int size);
double calculate_cofactor(t_matrix_4x4 *mtx, int omit_row, int omit_col, int size);
double calculate_determinant(t_matrix_4x4 *mtx, int size);

typedef struct s_submatrix_vars
{
	t_matrix_4x4	smtx;
	int				sub_row;
	int				sub_col;
	int				row;
	int				col;
} t_submatrix_vars;

typedef	struct s_determinant_vars
{
	double	cofactor_row_0_x_col_0;
	double	cofactor_row_0_x_col_1;
	double	cofactor_row_0_x_col_2;
	double 	cofactor_row_0_x_col_3;
	double	determinant;
} t_determinant_vars;

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


double calculate_cofactor(t_matrix_4x4 *mtx, int omit_row, int omit_col, int size)
{
    double minor;
    double cofactor;

    minor = calculate_minor(mtx, omit_row, omit_col, size);
    cofactor = pow(-1, omit_row + omit_col) * minor;
    return (cofactor);
}

double calculate_determinant(t_matrix_4x4 *mtx, int size)
{
    double determinant ;
    double cofactor;

    determinant = 0.0;
    cofactor = 0.0;

    if (size == 2)
    {
        determinant = mtx->entries[0][0] * mtx->entries[1][1] - mtx->entries[0][1] * mtx->entries[1][0];
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            double cofactor = calculate_cofactor(mtx, 0, i, size);
            determinant += mtx->entries[0][i] * cofactor;
        }
    }
    return (determinant);
}

double calculate_minor(t_matrix_4x4 *mtx, int omit_row, int omit_col, int size)
{
    t_matrix_4x4 minor_mtx = find_submatrix(mtx, omit_row, omit_col, size - 1);
    return calculate_determinant(&minor_mtx, size - 1);
}

bool is_invertible(t_matrix_4x4 *mtx, int size)
{
    double determinant;
    
    determinant = calculate_determinant(mtx, size);
    if (determinant == 0)
        return (false);
    return (true);
}

t_matrix_4x4	inverse_a_submatrix(t_matrix_4x4 *mtx, int size)
{
    t_matrix_4x4 inverse;

    if (is_invertible(mtx, ))
    {




    }
    return (inverse);
}




int	main(void)
{
	t_matrix_4x4	test2;
	t_matrix_4x4	test;
	double			res;
	double			res2;
	//double			res3;
	/*
	double			minor_1;
	double			cofactor_1;
	double			minor_2;
	double			cofactor_2;
	*/

	test2 = (t_matrix_4x4){
		.entries = {
	{1, 2, 6, 0},
	{-5, 8, -4, 0},
	{2, 6, 4, 0},
	{0, 0, 0, 0},
	}};

	test = (t_matrix_4x4){
		.entries = {
	{-2, -8, 3, 5},
	{-3, 1, 7, 3},
	{1, 2, -9, 6},
	{-6, 7, 7, -9},
	}};
	/*
	minor_1 = calculate_minor_matrix_3x3(&test, 0, 0, 2);
	cofactor_1 = calculate_cofactors_matrix_3x3(&test, 0, 0, 2);
	minor_2 = calculate_minor_matrix_3x3(&test, 1, 0, 2);
	cofactor_2 = calculate_cofactor_matrix_3x3(&test, 1, 0, 2);
	printf("minor: %f; cofactor: %f;\n", minor_1, cofactor_1);
	printf("minor: %f; cofactor: %f;\n", minor_2, cofactor_2);
	*/
	//res3 = calculate_determinant_matrix_3x3(&test2);
	res2 = calculate_determinant(&test2, 3);
	res = calculate_determinant(&test, 4);
	//printf("determinant: %f;\n", res3);
	printf("determinant: %f;\n", res2);
	printf("determinant: %f;\n", res);
	return (0);
}
