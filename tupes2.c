/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:39:16 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/21 17:07:33 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"


double find_magnitude(t_tuple *a)
{
	double result;
	
	if (a->type != Vector)
	{
		perror("No magnitude for a point. It has to be a vector.");
		exit(1);
	}
	result = sqrt(pow(a->x, 2) + pow(a->y, 2) + pow(a->z, 2));
	return (result);
}

t_tuple normalize_vector(t_tuple *a, double magnitude)
{
	t_tuple normalize;

	if (a->type != Vector)
	{
		perror("No normalization for a point. It has to be a vector.");
		exit(1);
	}
	normalize.x = a->x / magnitude;
	normalize.y = a->y / magnitude;
	normalize.z = a->z / magnitude;
	normalize.type = a->type;
}

double dot_product(t_tuple *a, t_tuple *b)
{
	double result;

	if (a->type != Vector)
	{
		perror("No normalization for a point. It has to be a vector.");
		exit(1);
	}
	result = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

//it will return a vector
t_tuple cross_product(t_tuple *a, t_tuple *b)
{
	t_tuple result;

	if (a->type != Vector || b->type != Vector)
	{
		perror("Vectors needed when finding the corss product.");
		exit(1);
	}
	result.x = a->y * b->z - a->z * b->y; 
	result.y = a->z * b->x - a->x * b->z;
	result.z = a->x * b->y - a->y * b->x;
	result.type = a->type;
	return (result);
}
