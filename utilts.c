/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:40:31 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/22 22:04:33 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "minirt.h"

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_all_int(int **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	free_stru(t_int_strs *struc)
{
	free_all_int(struc->rgb_strs);
	free_all_int(struc->values_strs);
}

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}
