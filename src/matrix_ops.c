/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:53:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/22 21:53:45 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	multi_process(t_mx *product, t_mx *mxa, t_mx *mxb)
{
	int		i;
	int		p_row_i;
	int		p_col_i;
	double	entry;

	p_row_i = 0;
	while (p_row_i < mxa->row_num)
	{
		p_col_i = 0;
		while (p_col_i < mxa->col_num)
		{
			entry = 0;
			i = 0;
			while (i < mxa->col_num)
			{
				entry += mxa->entries[p_row_i][i] * mxb->entries[i][p_col_i];
				i++;
			}
			product->entries[p_row_i][p_col_i] = entry;
			p_col_i++;
		}
		p_row_i++;
	}
}

void	mx_mult_error_msg(void)
{
	ft_putstr_fd(KRED, STDERR_FILENO);
	ft_putstr_fd("WARNING!!!:", STDERR_FILENO);
	ft_putstr_fd(KYEL, STDERR_FILENO);
	ft_putendl_fd("Matrix - Incorrect number of coloumns and rows found "
		"multiplication", STDERR_FILENO);
}

t_mx	mtxa_mult_mtxb(t_mx mtxa, t_mx mtxb)
{
	t_mx	res;

	if (mtxa.col_num != mtxb.row_num)
	{
		mx_mult_error_msg();
		return ((t_mx){0});
	}
	res = (t_mx){.row_num = mtxa.row_num, .col_num = mtxb.col_num};
	multi_process(&res, &mtxa, &mtxb);
	return (res);
}