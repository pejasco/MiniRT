/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:55:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/31 22:37:33 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include <stdio.h>

t_sphere sphere(int id, t_tuple origin_point)
{
	return ((t_sphere){
		.id = id,
		.origin_point = origin_point,
	});
}

double find_discirminant(t_sphere *s, t_ray *r, t_sphere_intersec_vars *vars)
{
	vars->sphere_to_ray = substract_tuples(&(r->origin_point), &(s->origin_point));
	vars->a = dot_product(&(r->vector), &(r->vector));
	vars->b = 2 * dot_product(&(r->vector), &(vars->sphere_to_ray));
	vars->c = dot_product(&(vars->sphere_to_ray), &(vars->sphere_to_ray)) - 1;
	vars->discriminant =  pow(vars->b, 2) - 4 * vars->a * vars->c;
	return (vars->discriminant);
}

void find_intersec(t_sphere *s, t_ray *r, t_sphere_intersec_vars *vars, t_intersec *intersec)
{
	t_tuple projected_direction_1;
	t_tuple projected_direction_2;

	r->t_1 = (-vars->b - pow(vars->discriminant, 0.5)) / (2 * vars->a);
	r->t_2 = (-vars->b + pow(vars->discriminant, 0.5)) / (2 * vars->a);
	projected_direction_1 = scale_tuple(&(r->vector), r->t_1);
	projected_direction_2 = scale_tuple(&(r->vector), r->t_2);
	intersec->intersec_1 = add_tuples(&(r->origin_point), &(projected_direction_1));
	intersec->intersec_2 = add_tuples(&(r->origin_point), &(projected_direction_2));
}


t_intersec sphere_intersec(t_sphere *s, t_ray *r)
{
	t_intersec	intersec;
	t_sphere_intersec_vars vars;

	if (find_discirminant(s, r, &vars) < 0)
	{
		intersec.intersec_1 = r->origin_point;
		intersec.intersec_2 = r->origin_point;
		return (intersec);
	}
	find_intersec(s, r, &vars, &intersec);
	return (intersec);
}

