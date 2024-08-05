/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:23:46 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/05 12:35:58 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_tuple	create_tuple(double x, double y, double z, t_tuple_type type)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.type = type;
	if (tuple.type == Vector)
		tuple.w = 0;
	else if (tuple.type == Point)
		tuple.w = 1;
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

t_tuple subtract_tuples(const t_tuple *a, const t_tuple *b)
{
    t_tuple subtract;

    subtract.x = a->x - b->x;
    subtract.y = a->y - b->y;
    subtract.z = a->z - b->z;

    if (a->type == Point && b->type == Point)
    {
        subtract.type = Vector;
    }
    else if (a->type == Vector && b->type == Point)
    {
        subtract.type = Point;
    }
    else
    {
        subtract.type = a->type;
    }

    return subtract;
}

/*
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
*/

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

t_tuple	point_minus_point(const t_tuple *a, const t_tuple *b)
{
	t_tuple	substract;

	substract.x = a->x - b->x;
	substract.y = a->y - b->y;
	substract.z = a->z - b->z;
	substract.type = Vector;
	if (a->type == Point && b->type == Vector)
		substract.type = Point;
	return (substract);
}

t_tuple multiply_tuple_with_matrix(t_tuple *tuple, t_matrix_4x4 *matrix)
{
    t_tuple result;

    result.x = matrix->entries[0][0] * tuple->x + matrix->entries[0][1] * tuple->y +
                matrix->entries[0][2] * tuple->z + matrix->entries[0][3] * tuple->w;
    result.y = matrix->entries[1][0] * tuple->x + matrix->entries[1][1] * tuple->y +
                matrix->entries[1][2] * tuple->z + matrix->entries[1][3] * tuple->w;
    result.z = matrix->entries[2][0] * tuple->x + matrix->entries[2][1] * tuple->y +
                matrix->entries[2][2] * tuple->z + matrix->entries[2][3] * tuple->w;
    result.w = matrix->entries[3][0] * tuple->x + matrix->entries[3][1] * tuple->y +
                matrix->entries[3][2] * tuple->z + matrix->entries[3][3] * tuple->w;
    if (result.w == 1)
        result.type = Point;
    else
        result.type = Vector;
    return result;
}

