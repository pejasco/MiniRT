/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:49:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/01 14:33:39 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate->scale->translate

#include "../inc/minirt.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_invertible(t_matrix_4x4 *mtx, int size)
{
    double determinant;
    
    determinant = calculate_determinant(mtx, size);
    if (determinant == 0)
        return (false);
    return (true);
}

t_matrix_4x4 process_a_cofactor_matrix(t_matrix_4x4 *mtx, int size)
{
	t_matrix_4x4 cofactor_mtx;
    int i;
    int j;

	cofactor_mtx = (create_matrix_filled_with_zero());
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            cofactor_mtx.entries[i][j] 
                = calculate_cofactor(mtx, i, j, size);
            j++;
        }
        i++;
    }
    return (cofactor_mtx);
}

t_matrix_4x4 inverse_a_matrix(t_matrix_4x4 *mtx, int size)
{
    t_matrix_4x4 cofactor_mtx;
    double determinant;
    t_matrix_4x4 adjugate_mtx;
    int i;
    
    if (is_invertible(mtx, size) == 0)
    {
        printf("The matrix is not invertible!");
        cofactor_mtx = create_matrix_filled_with_zero();
        return cofactor_mtx;
    }
    cofactor_mtx = process_a_cofactor_matrix(mtx, size);
    determinant = calculate_determinant(mtx, size);
    adjugate_mtx = transpose_a_matrix(&cofactor_mtx);
    i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            adjugate_mtx.entries[i][j] /= determinant;
            j++;
        }
        i++;
    }
    return (adjugate_mtx);
}
