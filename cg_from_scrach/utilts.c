/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:40:31 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/20 17:00:44 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "miniRT.h"

bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	else
		return (false);
}
