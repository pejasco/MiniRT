/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:40:31 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/23 15:08:46 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "minirt.h"

void	px_coord_swap(t_px_coord *a, t_px_coord *b)
{
	t_px_coord	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	round_double(double n)
{
	if (n > 0)
		return ((int)(n + 0.5));
	else
		return ((int)(n - 0.5));
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}
