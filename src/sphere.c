/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:55:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/02 13:58:15 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../lib/libft/libft.h"
#include <math.h>
#include <stdio.h>

t_sphere create_sphere(int id, t_tuple origin_point)
{
	return ((t_sphere){
		.type = "Sphere",
		.id = id,
		.origin_point = origin_point,
	});
}

double find_discirminant(t_sphere *s, t_ray *r, t_sphere_intersec_vars *vars)
{
	vars->sphere_to_ray = point_minus_point(&(r->origin_point), &(s->origin_point));
	vars->a = dot_product(&(r->vector), &(r->vector));
	vars->b = 2 * dot_product(&(r->vector), &(vars->sphere_to_ray));
	vars->c = dot_product(&(vars->sphere_to_ray), &(vars->sphere_to_ray)) - 1;
	vars->discriminant =  pow(vars->b, 2) - 4 * vars->a * vars->c;
	return (vars->discriminant);
}

void find_intersec(t_ray *r, t_sphere_intersec_vars *vars, t_intersect_pts *intersec)
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

t_intersect_pts sphere_intersec_pts(t_sphere *s, t_ray *r)
{
	t_intersect_pts	intersec;
	t_sphere_intersec_vars vars;

	if (find_discirminant(s, r, &vars) < 0)
	{
		intersec.intersec_1 = r->origin_point;
		intersec.intersec_2 = r->origin_point;
		return (intersec);
	}
	find_intersec(r, &vars, &intersec);
	return (intersec);
}

t_distance intersect(t_sphere *s, t_ray *r)
{
	t_distance				distance;
	t_sphere_intersec_vars	vars;

	distance.count = 0;
	distance.t[0] = 0;
	distance.t[1] = 0;
	vars.discriminant = find_discirminant(s, r, &vars);	
	if(vars.discriminant < 0)
		printf("No interceptions found\n");
	else if (vars.discriminant >= 0)
	{
		distance.count = 2;
		distance.t[0] = (-vars.b - pow(vars.discriminant, 0.5)) / (2 * vars.a);
		distance.t[1] = (-vars.b + pow(vars.discriminant, 0.5)) / (2 * vars.a);
	}
	return (distance);
}

//only the visible intersection
//we call it hit
t_intersection create_intersection(t_sphere *object, double t)
{
	t_intersection product;

	product.object = object;
	product.t = t;
	return (product);
} 

t_intersection **create_intersections(t_intersection **current_arry,
	t_intersection *i1, t_intersection *i2)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	t_intersection **arry;

    if (current_arry == NULL)
    {
        arry = malloc(sizeof(t_intersection *) * 3);
        if (arry == NULL)
		{
            perror("Failed to allocate memory for intersections");
            exit(1);
        }
        arry[0] = i1;
        arry[1] = i2;
        arry[2] = NULL;
		arry[0]->count = 2;
    }
    else
    {
        while (current_arry[i])
            ++i;
        arry = malloc(sizeof(t_intersection *) * (i + 2 + 1));
        if (arry == NULL)
        {
            perror("Failed to allocate memory for intersections");
            exit(1);
        }
		i = 0;
        while (current_arry[j])
		{
			arry[j] = current_arry[j];
			++j;
		}
        arry[j] = i1;
        arry[j+1] = i2;
        arry[j+2] = NULL;
		arry[0]->count = current_arry[0]->count + 2; 
        free(current_arry);
    }
	return (arry);
}

t_intersection **sort_intersections(t_intersection **current_arry)
{
	int				count;
	t_intersection	*temp;
	t_intersection 	**arry = NULL;
	int				i;
	int				j;
	int				swapped;

	count = current_arry[0]->count;
	arry = malloc(sizeof(t_intersection  *) * (count + 1));
	i = 0;
	while (current_arry[i])
	{
		arry[i] = current_arry[i];
		++i;
	}
	i = 0;
	while (i < count - 1)
	{
		swapped = 0;
		j = 0;
		while (j < count - i -1)
		{
			if (arry[j]->t > arry[j + 1]->t)
			{
				temp = arry[j];
				arry[j] = arry[j + 1];
				arry [j + 1] = temp;
				swapped = 1;
			}
			++j;
		}
		if (swapped == 0)
			break;
		++i;
	}
	free(current_arry);
	return (arry);
}



void print_arry(t_intersection **arry)
{
	int		i;

	i = 0;
	while (arry[i])
	{
		printf("###################################\n");
		printf("\033[1;34m");
		printf("Object: %s  | ", arry[i]->object->type);
		printf("ID: %d\n", arry[i]->object->id);
		printf("-----------------------------------\n");
		printf("\033[0m");
		printf("Distance: %f\n", arry[i]->t);
		printf("###################################\n");
		printf("\n");
		i++;
	}
	printf("\033[1;31m");
	printf("Total nbr of intersections: %d\n", arry[0]->count);
	printf("\033[0m");
}

int main(void)
{
	t_sphere	s_1;
	t_ray		r_1;
	t_tuple		s_org_1;
	t_tuple		r_org_1;
	t_tuple		r_dir_1;
	t_distance	res_1;
	t_intersection intersection_1a;
	t_intersection intersection_1b;

	t_sphere	s_2;
	t_ray		r_2;
	t_tuple		s_org_2;
	t_tuple		r_org_2;
	t_tuple		r_dir_2;
	t_distance	res_2;
	t_intersection intersection_2a;
	t_intersection intersection_2b;
	t_intersection **arry = NULL;

	s_org_1 = create_tuples(0, 0, 0, Point);
	//positive (t0: 4 & t1: 6)
	//r_org_1 = create_tuples(0, 0, -5, Point);
	//r_dir_1 = create_tuples(0, 0, 1, Vector);
	
	//negative (t0: -6 & t1: -4)
	r_org_1 = create_tuples(0, 0, 5, Point);
	r_dir_1 = create_tuples(0, 0, 1, Vector);

	s_1 = create_sphere(0, s_org_1);
	r_1 = create_ray(r_org_1, r_dir_1);
	res_1 = intersect(&s_1, &r_1);
	printf("count: %d\n", res_1.count);
	printf("t[0]: %f\n", res_1.t[0]);	
	printf("t[1]: %f\n", res_1.t[1]);

	s_org_2 = create_tuples(0, 0, 0, Point);
	r_org_2 = create_tuples(0, 1, -5, Point);
	r_dir_2 = create_tuples(0, 0, 1, Vector);
	s_2 = create_sphere(1, s_org_2);
	r_2 = create_ray(r_org_2, r_dir_2);
	res_2 = intersect(&s_2, &r_2);
	printf("count: %d\n", res_2.count);
	printf("t[0]: %f\n", res_2.t[0]);	
	printf("t[1]: %f\n", res_2.t[1]);

	intersection_1a = create_intersection(&s_1, res_1.t[0]);
	intersection_1b = create_intersection(&s_1, res_1.t[1]);
	//arry = create_intersections(arry, &intersection_1a, &intersection_1b);
	//print_arry(arry);
	intersection_2a = create_intersection(&s_2, res_2.t[0]);
	intersection_2b = create_intersection(&s_2, res_2.t[1]);
	arry = create_intersections(arry, &intersection_1a, &intersection_1b);
	arry = create_intersections(arry, &intersection_2a, &intersection_2b);
	print_arry(arry);
	arry = sort_intersections(arry);
	print_arry(arry);
}

/*
int main(void)
{
	t_sphere	s;
	t_ray		r;
	t_tuple		s_org;
	t_tuple		r_org;
	t_tuple		r_dir;
	t_distance	res;		

	s_org = create_tuples(0, 0, 0, Point);
	r_org = create_tuples(0, 0, 5, Point);
	r_dir = create_tuples(0, 0, 1, Vector);
	s = create_sphere(0, s_org);
	r = create_ray(r_org, r_dir);
	res = intersect(&s, &r);
	printf("count: %d\n", res.count);
	printf("t[0]: %f\n", res.t[0]);	
	printf("t[1]: %f\n", res.t[1]);
}
*/
/*
t_matrix_4x4 scale_matrix(double x, double y, double z)
{
	t_matrix_4x4 translate;

	translate = (t_matrix_4x4){
		.entries = {
	{x, 0, 0, 0},
	{0, y, 0, 0},
	{0, 0, z, 0},
	{0, 0, 0, 1},
	}};
	return (translate);
}
*/