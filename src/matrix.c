/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:10:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/01 14:33:39 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate->scale->translate

#include <stdbool.h>
#include "../inc/minirt.h"
#include <stdio.h>
#include <assert.h>

bool	are_the_same_matrix(const t_matrix_4x4 *a, const t_matrix_4x4 *b)
{
	int	i;
	int	y;

	i = 0;
	while (i < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (a->entries[i][y] != b->entries[i][y])
				return (false);
			y++;
		}
		i++;
	}
	return (true);
}

//order matters
t_matrix_4x4	multiply_matrices(const t_matrix_4x4 *a, const t_matrix_4x4 *b)
{
	int row;
	int	col;
	t_matrix_4x4 result;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.entries[row][col] = a->entries[row][0] * b->entries[0][col]
									+ a->entries[row][1] * b->entries[1][col]
									+ a->entries[row][2] * b->entries[2][col]
									+ a->entries[row][3] * b->entries[3][col];
			col++;
		}
		row++;
	}
	return (result);
}


/*
t_matrix_4x1	matrix_multiply_tuple(const t_matrix_4x4 *a, const t_tuple *b)
{
	int row;
	t_matrix_4x1 result;

	row = 0;
	while (row < 4)
	{
			result.entries[row][0] = a->entries[row][0] * b->x;
									+ a->entries[row][1] * b->y;
									+ a->entries[row][2] * b->z;
									+ a->entries[row][3] * b->w;
		row++;
	}
	return (result);
}
*/
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
/*
Cof(A) = [ cof(a) cof(b) cof(c) cof(d) ]
         [ cof(e) cof(f) cof(g) cof(h) ]
         [ cof(i) cof(j) cof(k) cof(l) ]
         [ cof(m) cof(n) cof(o) cof(p) ]
*/
/*
Adj(A) = [ cof(a) cof(e) cof(i) cof(m) ]
         [ cof(b) cof(f) cof(j) cof(n) ]
         [ cof(c) cof(g) cof(k) cof(o) ]
         [ cof(d) cof(h) cof(l) cof(p) ]
*/

t_matrix_4x4	transpose_a_matrix(const t_matrix_4x4 *mtx)
{
	int row;
	int col;
	t_matrix_4x4 transpose;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			transpose.entries[row][col] = mtx->entries[col][row];	
			col++;
		}
		row++;
	}
	return (transpose);
}

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

/*
int main(void)
{
	t_matrix_4x4 haha;

	haha = (t_matrix_4x4){
		.entries = {
	{1, 2, 3, 4},
	{5.5, 6.5, 7.5, 8.5},
	{9, 10, 11, 12},
	{13.5, 14.5, 15.5, 16.5},
	}};
	
	assert(haha.entries[0][0] == 1);
	assert(haha.entries[1][2] == 7.5);
	printf("diuuuuuuuuuuuuuuuuuu\n");
	assert(haha.entries[3][2] == 999);
	assert(haha.entries[3][3] == 16.5);
	return (0);
}
*/