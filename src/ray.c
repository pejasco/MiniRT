/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:22:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/01 16:10:11 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate->scale->translate

#include <stdbool.h>
#include "../inc/minirt.h"
#include <stdio.h>
#include <assert.h>

t_ray	create_ray(t_tuple point, t_tuple vector)
{
	t_ray	ray;
	
	ray.origin_point = point;
	ray.vector = vector;
	return (ray);
}


t_tuple	position(t_ray *ray, double speed)
{
	t_tuple scale;

	scale = scale_tuple(&(ray->vector), speed);
	return (add_tuples(&(ray->origin_point), &scale));
}
