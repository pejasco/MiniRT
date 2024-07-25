/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:06:19 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/25 11:51:13 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"


typedef struct s_matrix_4x4
{
	double entries[4][4];
} t_matrix_4x4;

t_matrix_4x4 create_matrix_filled_with_zero(void)
{
    t_matrix_4x4 mtx_with_zero;

	mtx_with_zero =(t_matrix_4x4){
				.entries = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		}};
		return t_matrix_4x4;
}

double determinant_matrix_(t_matrix_4x4 *mtx)
{
    double result;

    result = (mtx->entries[0][0] * mtx->entries[1][1] 
        - mtx->entries[0][1] * mtx->entries[1][0]);
    return (result);
}

t_matrix_4x4 find_submatrix(t_matrix_4x4 *mtx,
    int omit_row, int omit_col, int sub_mtx_dimen)
{
    t_matrix_4x4 submatrix;
	int		sub_row;
	int		sub_col;
	int		row;
	int		col;

	sub_row = 0;
	row = 0;
    submatrix = create_matrix_filled_with_zero();
	while (sub_row < sub_mtx_dimen && row < (sub_mtx_dimen + 1))
	{
		sub_col = 0;
		col = 0;
		if (row == omit_row)
			++row;
		while (sub_col < sub_mtx_dimen && sub_row )
		{
			if (col == omit_col)
				++col;
			submatrix[sub_row][sub_col] =			


			++sub_col;
		}
		++sub_row;
	}
	retrun (submatrix);
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