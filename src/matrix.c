/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:10:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/23 16:46:54 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "minirt.h"
#include <stdio.h>

double **alloc_mem_for_mtx(int row, int column)
{
	int		i;
	int 	y;

	i = 0;
	// row x column matrix
	double  **mtx = malloc(row * sizeof(double *));
	while (i < row)
	{
		mtx[i] = malloc(column * sizeof(double));
		i++;
	}
	return (mtx);
}

/*
double values[4][4] = {
    {1, 2, 3, 4},
    {5.5, 6.5, 7.5, 8.5},
    {9, 10, 11, 12},
    {13.5, 14.5, 15.5, 16.5}
};
*/

void assign_matrix_4x4(double **matrix, double **values)
{
	y = 0;
	while (y < column)
	{
		
		y++;
	}
	i++;
}






void create_matrix_4x4(double *nbr_for_matrix)
{
	assert(ma)



}