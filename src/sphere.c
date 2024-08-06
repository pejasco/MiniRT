/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:55:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/06 23:49:19 by chuleung         ###   ########.fr       */
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
		.transform = (t_matrix_4x4){{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1},
		}}
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
	//if(vars.discriminant < 0)
		//printf("No interceptions found\n");
	if (vars.discriminant >= 0)
	{
		distance.count = 2;
		distance.t[0] = (-vars.b - pow(vars.discriminant, 0.5)) / (2 * vars.a);
		distance.t[1] = (-vars.b + pow(vars.discriminant, 0.5)) / (2 * vars.a);
		printf("t0: %f, t1: %f\n ", distance.t[0], distance.t[1]);
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
    int     i;
    int     j;
    
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

t_intersection *find_hit(t_intersection **current_arry)
{
    int count = 2; // assuming there are always 2 intersections
    t_intersection *temp;
    t_intersection **arry = malloc(sizeof(t_intersection *) * count);
    if (arry == NULL) {
        perror("Failed to allocate memory for sorted intersections");
        exit(1);
    }
    arry[0] = current_arry[0];
    arry[1] = current_arry[1];

    // Sort the intersections
    for (int i = 0; i < count - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arry[j]->t > arry[j + 1]->t)
            {
                temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
	return (arry[0]);
}


/*
t_intersection **sort_intersections(t_intersection **current_arry)
{
    int count = 2; // assuming there are always 2 intersections
    t_intersection *temp;
    t_intersection **arry = malloc(sizeof(t_intersection *) * count);
    if (arry == NULL) {
        perror("Failed to allocate memory for sorted intersections");
        exit(1);
    }
    arry[0] = current_arry[0];
    arry[1] = current_arry[1];

    for (int i = 0; i < count - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (arry[j]->t > arry[j + 1]->t)
            {
                temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    return arry;
}
*/

/*
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
	i = 0;
	while (i < count - 1)
	{
		arry[i]->order = i;
		i++;
	}
	free(current_arry);
	return (arry);
}
*/
/*
t_intersection *find_hit(t_intersection **arry)
{
    int	i;
    int count;

    while (i < count + 1)
    {
        if (arry[i]->t >= 0)
            return arry[i];
        i++;
    }
    return (NULL);
}
*/

/*
t_intersection *find_hit(t_intersection **arry, int current_item_order)
{
    int	i;
    int count;

    i = 0;
    count = arry[0]->count;
    if (current_item_order >= count)
        return (NULL);
    
    i = current_item_order + 1;
    while (i < count + 1)
    {
        if (arry[i]->t >= 0)
            return arry[i];
        i++;
    }
    return (NULL);
}
*/

void set_tranform(t_sphere *s, t_matrix_4x4 *mtx)
{
	s->transform = *(mtx);
}

void print_intersection(t_intersection *intersection)
{
		printf("###################################\n");
		printf("\033[0;33m");
		printf("Object: %s  | ", intersection->object->type);
		printf("ID: %d\n", intersection->object->id);
		printf("-----------------------------------\n");
		printf("\033[0m");
		printf("Distance: %f\n",intersection->t);
		printf("###################################\n");
		printf("\n");
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

// int	main(void)
// {
// 	/*
//     t_ray r = create_ray(create_tuples(0, 0, -5, Point), create_tuples(0, 0, 1, Vector));
//     t_sphere s = create_sphere(0, create_tuples(0, 0, 0, Point));
//     t_matrix_4x4 scaling_mtx = scale_matrix(2, 2, 2);
//     set_tranform(&s, &scaling_mtx);
// 	t_matrix_4x4 inverse_matrix = inverse_a_matrix(&(s.transform), 4);
// 	t_ray new_r = transform_ray(&r, &inverse_matrix);
//     t_distance xs = intersect(&s, &new_r);
//     printf("Intersections count: %d\n", xs.count);
//     printf("First intersection: %f\n", xs.t[0]);
//     printf("Second intersection: %f\n", xs.t[1]);
// 	*/


//     t_ray r = create_ray(create_tuples(0, 0, -5, Point), create_tuples(0, 0, 1, Vector));
//     t_sphere s = create_sphere(0, create_tuples(0, 0, 0, Point));
//     t_matrix_4x4 translating_mtx = translate_matrix(5, 0, 0);
//     set_tranform(&s, &translating_mtx);
// 	t_matrix_4x4 inverse_matrix = inverse_a_matrix(&(s.transform), 4);
// 	t_ray new_r = transform_ray(&r, &inverse_matrix);
//     t_distance xs = intersect(&s, &new_r);
//     printf("Intersections count: %d\n", xs.count);
//     printf("First intersection: %f\n", xs.t[0]);
//     printf("Second intersection: %f\n", xs.t[1]);


//     return 0;
// }

/*
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
	t_intersection *hit = NULL;
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

	//positive (t0: 5 & t1: 5)
	//s_org_2 = create_tuples(0, 0, 0, Point);
	//r_org_2 = create_tuples(0, 1, -5, Point);
	//r_dir_2 = create_tuples(0, 0, 1, Vector);

	//positive (t0: 4 & t1: 6)
	s_org_2 = create_tuples(0, 0, 0, Point);
	r_org_2 = create_tuples(0, 0, -5, Point);
	r_dir_2 = create_tuples(0, 0, 1, Vector);

	//positive (t0: -1 & t1: 1)
	//s_org_2 = create_tuples(0, 0, 0, Point);
	//r_org_2 = create_tuples(0, 0, 0, Point);
	//r_dir_2 = create_tuples(0, 0, 1, Vector);

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
	hit = find_hit(arry, 0);
	print_intersection(hit);
	hit = find_hit(arry, 1);
	print_intersection(hit);
	hit = find_hit(arry, 2);
	print_intersection(hit);
}
*/

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

