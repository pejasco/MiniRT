/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:22:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/05 22:41:34 by chuleung         ###   ########.fr       */
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

t_tuple	find_position_of_ray(t_ray *ray, double speed)
{
	t_tuple scale;

	scale = scale_tuple(&(ray->vector), speed);
	return (add_tuples(&(ray->origin_point), &scale));
}

t_ray transform_ray(t_ray *ray, t_matrix_4x4 *mtx)
{
	t_ray	tranformed_ray;

	tranformed_ray.origin_point =
		multiply_tuple_with_matrix(&(ray->origin_point), mtx);
	tranformed_ray.vector =
		multiply_tuple_with_matrix(&(ray->vector), mtx);
	return (tranformed_ray);
}

void print_ray(t_ray *ray)
{
	printf("###################################\n");
	printf("\033[0;33m");
	printf("Origin (x): %f\n", ray->origin_point.x);
	printf("Origin (y): %f\n", ray->origin_point.y);
	printf("Origin (z): %f\n", ray->origin_point.z);
	printf("Origin (w): %f\n", ray->origin_point.w);
	printf("-----------------------------------\n");
	printf("\033[0m");
	printf("Vector (x): %f\n", ray->vector.x);
	printf("Vector (y): %f\n", ray->vector.y);
	printf("Vector (z): %f\n", ray->vector.z);
	printf("Vector (w): %f\n", ray->vector.w);
	printf("###################################\n");
	printf("\n");
}

/*
int main(void)
{
	t_ray			ray;
	t_matrix_4x4	mtx;
	t_tuple			r_org_1;
	t_tuple			r_dir_1;
	t_ray			result;

//tanslate

	r_org_1 = create_tuples(1, 2, 3, Point);
	r_dir_1 = create_tuples(0, 1, 0, Vector);
	ray = create_ray(r_org_1, r_dir_1);
	print_ray(&ray);
	
	mtx = translate_matrix(3, 4, 5);
	result = tranform_ray(&ray, &mtx);
	print_ray(&result);


//scale
	r_org_1 = create_tuples(1, 2, 3, Point);
	r_dir_1 = create_tuples(0, 1, 0, Vector);
	ray = create_ray(r_org_1, r_dir_1);
	print_ray(&ray);
	
	mtx = scale_matrix(2, 3, 4);
	result = tranform_ray(&ray, &mtx);
	print_ray(&result);
}
*/