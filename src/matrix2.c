/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:06:19 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/25 00:02:56 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix_4x4 create_matrix_filled_with_zero(void)
{
    t_matrix_4x4 mtx_with_zero

    



}


double determinant_matrix_(t_matrix_4x4 *mtx)
{
    double result;

    result = (mtx->entries[0][0] * mtx->entries[1][1] 
        - mtx->entries[0][1] * mtx->entries[1][0]);
    return (result);
}

t_matrix_4x4 find_submatrix(t_matrix_4x4 *mtx,
    int omit_row, int omit_col, int dimension)
{
    t_matrix_4x4 submatrix;

    submatrix = (mtx->entries)



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