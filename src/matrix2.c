/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:42:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/30 18:20:33 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate->scale->translate

#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

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
    return (calculate_determinant(&minor_mtx, size - 1));
}


//rotate -> scale -> translate

/*
int	main(void)
{
	t_matrix_4x4	a;
	t_matrix_4x4	b;
	t_matrix_4x4	c;
	t_matrix_4x4	inverse_b;
	t_matrix_4x4	res;

	a = (t_matrix_4x4){
		.entries = {
	{3, -9, 7, 3},
	{3, -8, 2, -9},
	{-4, 4, 4, 1},
	{-6, 5, -1, 1},
	}};

	b = (t_matrix_4x4){
		.entries = {
	{8, 2, 2, 2},
	{3, -1, 8, 0},
	{7, 0, 5, 4},
	{6, -2, 0, 5},
	}};

	c = multiply_matrices(&a, &b); 
	inverse_b = inverse_a_matrix(&b, 4);
	res = multiply_matrices(&c, &inverse_b);
	print_matrix(&res);
}
*/

/*
int	main(void)
{
	t_matrix_4x4	test;
	t_matrix_4x4	test1;
	t_matrix_4x4	test2;
	t_matrix_4x4	result;
	t_matrix_4x4	result1;
	t_matrix_4x4	result2;

	test = (t_matrix_4x4){
		.entries = {
	{-5, 2, 6, -8},
	{1, -5, 1, 8},
	{7, 7, -6, -7},
	{1, -3, 7, 4},
	}};

	test1 = (t_matrix_4x4){
		.entries = {
	{8, -5, 9, 2},
	{7, 5, 6, 1},
	{-6, 0, 9, 6},
	{-3, 0, -9, -4},
	}};

	test2 = (t_matrix_4x4){
		.entries = {
	{9, 3, 0, 9},
	{-5, -2, -6, -3},
	{-4, 9, 6, 4},
	{-7, 6, 6, 2},
	}};

	result = inverse_a_matrix(&test, 4);
	result1 = inverse_a_matrix(&test1, 4);
	result2 = inverse_a_matrix(&test2, 4);
	print_matrix(&result);
	print_matrix(&result1);
	print_matrix(&result2);
}
*/

/*
int	main(void)
{
	t_matrix_4x4	test2;
	t_matrix_4x4	test;
	double			res;
	double			res2;
	//double			res3;
	double			minor_1;
	double			cofactor_1;
	double			minor_2;
	double			cofactor_2;


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

	minor_1 = calculate_minor_matrix_3x3(&test, 0, 0, 2);
	cofactor_1 = calculate_cofactors_matrix_3x3(&test, 0, 0, 2);
	minor_2 = calculate_minor_matrix_3x3(&test, 1, 0, 2);
	cofactor_2 = calculate_cofactor_matrix_3x3(&test, 1, 0, 2);
	printf("minor: %f; cofactor: %f;\n", minor_1, cofactor_1);
	printf("minor: %f; cofactor: %f;\n", minor_2, cofactor_2);

	//res3 = calculate_determinant_matrix_3x3(&test2);
	res2 = calculate_determinant(&test2, 3);
	res = calculate_determinant(&test, 4);
	//printf("determinant: %f;\n", res3);
	printf("determinant: %f;\n", res2);
	printf("determinant: %f;\n", res);
	return (0);
}
*/

/*
Yes, there is a difference between the inverse of the transpose of a matrix and the transpose of the inverse of a matrix. However, for any square matrix A, the following property holds:

(A^T)^-1 = (A^-1)^T

This means that the inverse of the transpose of a matrix A is equal to the transpose of the inverse of A. This property is known as the "Inverse Transpose Property".

It's important to note that this property only holds for invertible (or nonsingular) matrices. If a matrix is not invertible (or singular), its inverse does not exist.
*/