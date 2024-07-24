/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:23:46 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/24 14:36:25 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	create_tuples(double x, double y, double z, double w, t_tuple_type type)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;

	tuple.type = type;
	return (tuple);
}

t_tuple	add_tuples(const t_tuple *a, const t_tuple *b)
{
	t_tuple	addition;

	addition.x = a->x + b->x;
	addition.y = a->y + b->y;
	addition.z = a->z + b->z;
	if (a->type == Point && b->type == Point)
	{
		perror("2 points cannot be added together");
		exit(1);
	}
	else if ((a->type == Point && b->type == Vector)
		|| (a->type == Vector && b->type == Point))
		addition.type = Point;
	else
		addition.type = Vector;
	return (addition);
}

t_tuple	substract_tuples(const t_tuple *a, const t_tuple *b)
{
	t_tuple	substract;

	if (a->type == Point && b->type == Point)
	{
		perror("2 points cannot be subtracted");
		exit(1);
	}
	else if (a->type == Vector && b->type == Point)
	{
		substract.x = b->x - a->x;
		substract.y = b->y - a->y;
		substract.z = b->z - a->z;
		substract.type = Point;
	}
	else
	{
		substract.x = a->x - b->x;
		substract.y = a->y - b->y;
		substract.z = a->z - b->z;
		substract.type = Vector;
		if (a->type == Point && b->type == Vector)
			substract.type = Point;
	}
	return (substract);
}

t_tuple	negate_tuple(const t_tuple *a)
{
	t_tuple	negate;

	negate.x = -(a->x);
	negate.y = -(a->y);
	negate.z = -(a->z);
	negate.type = (a->type);
	return (negate);
}

t_tuple scale_tuple(const t_tuple *a, double scale)
{
	t_tuple result;

	result.x = a->x * scale;
	result.y = a->y * scale;
	result.z = a->z * scale;
	result.type = a->type;
	return (result);
}
