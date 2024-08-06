/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:45:07 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/06 23:54:56 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
    t_vars          vars;
    t_ray           r;
    t_sphere        s;
    t_tuple         ray_origin;
    t_tuple         target_wall_point;
    t_tuple         ray_direction;
    t_tuple         normalized_ray_direction;
    t_distance      distance;
    t_intersection  a;
    t_intersection  b;
    t_intersection  **intersection_arry;
    t_px_coord      canvas_coord;
    t_intersection  *hit; // Added hit variable

    double      wall_size;
    double      canvas_pixel;
    double      pixel_size;
    double      half;
    double      magnitude;

    int         pixel_x = 0;
    int         pixel_y = 0;
    int         world_x;
    int         world_y;
    int         wall_z = 10;

    window_handle(&vars);
    ray_origin = create_tuple(0, 0, -5, Point);
    wall_size = 7.0;
    canvas_pixel = 100;
    pixel_size = wall_size / canvas_pixel;
    half = wall_size / 2;
    create_canvas(&vars, 100, 100, WHITE);
    //create_canvas(&vars.img_vars, 100, 100, WHITE);
    s = create_sphere(0, create_tuple(0, 0, 0, Point));

    while (pixel_y < canvas_pixel - 1)
    {
        world_y = half - pixel_size * pixel_y;
        //world_y = half - pixel_size * pixel_y;
        pixel_x = 0; // reset pixel_x for each row
        while (pixel_x < canvas_pixel - 1)
        {
            world_x = -half + pixel_size * pixel_x;
            //world_x = -half + pixel_size * pixel_x;
            target_wall_point = create_tuple(world_x, world_y, wall_z, Point);
            ray_direction = subtract_tuples(&target_wall_point, &ray_origin);
            magnitude = find_magnitude(&ray_direction);
            normalized_ray_direction = normalize_vector(&ray_direction, magnitude);
            r = create_ray(ray_origin, normalized_ray_direction);
            distance = intersect(&s, &r);
            if (distance.count > 0) // if there are intersections
            {
                a = create_intersection(&s, distance.t[0]);
                b = create_intersection(&s, distance.t[1]);
                intersection_arry = create_intersections(NULL, &a, &b);
                hit = find_hit(intersection_arry); // find the hit
                if (hit != NULL) // if there is a hit
                {

                    printf("x: %d y: %d intercepted!\n", pixel_x, pixel_y);
                    canvas_coord = (t_px_coord){.x = pixel_x, .y = canvas_pixel - pixel_y - 1, .rgb = RED};
                    supa_pixel_put(&vars, canvas_coord, RED);
                }
                free(intersection_arry); // free the memory allocated for intersection_arry
            }
             pixel_x++; // increment pixel_x for each pixel in the row
        }
        pixel_y++; // increment pixel_y for each row
    }

    put_image_to_window_vars(&vars);
    set_up_hooks(&vars);
    mlx_loop(vars.mlx_ptr);
    window_close(&vars);

    return 0;
}

/*
Canvas Pixels (0,0) -------------------> (100,0)
                |                         |
                |                         |
                V                         V
World Coords (-3.5,3.5) ---------------> (3.5,3.5)


*/

/*
int main(void)
{
	t_vars		vars;
    t_ray		r;
	t_sphere 	s;
	t_tuple     r_origin;
    t_tuple     wall_point;
    double      wall_size;
    double      canvas_pixel;
    double      pixel_size;
    

	window_handle(&vars);
    r_origin = create_tuple(0, 0, -5, Point);
    wall_point = create_tuple(0, 0, -5, Point);
    wall_size = 7.0;
    canvas_pixel = 100;
    
    





    //create_canvas(&vars.img_vars, WIDTH, HEIGHT, RED);
	put_image_to_window_vars(&vars);
	set_up_hooks(&vars);
	mlx_loop(vars.mlx_ptr);
	window_close(&vars);
}

*/



/*
int main(void)
{
    t_vars vars;

    t_tuple ray_origin = create_tuples(0, 0, -5, Point);
    double wall_z = 10.0;
    double wall_size = 7.0;
    int canvas_pixels = 100;
    double pixel_size = wall_size / canvas_pixels;
    double half = wall_size / 2;

    t_img img_vars;
    t_argb rgb = argb(0, 255, 0, 0); // red
    t_argb black = argb(0, 0, 0, 0); // black
    create_canvas(&img_vars, canvas_pixels, canvas_pixels, black);
    t_sphere shape = create_sphere(1, create_tuples(0, 0, 0, Point));

    int y = 0;
    while (y < canvas_pixels) 
    {
        double world_y = half - pixel_size * y;
        int x = 0;
        while (x < canvas_pixels) 
        {
            double world_x = -half + pixel_size * x;
            t_tuple position = create_tuples(world_x, world_y, wall_z, Point);
            t_tuple direction = subtract_tuples(&position, &ray_origin);
            double magnitude = find_magnitude(&direction);
            t_tuple normalized_direction = normalize_vector(&direction, magnitude);
            t_ray r = create_ray(ray_origin, normalized_direction);
            t_distance distance = intersect(&shape, &r);
            t_intersection *i1 = malloc(sizeof(t_intersection));
            t_intersection *i2 = malloc(sizeof(t_intersection));
            if (i1 == NULL || i2 == NULL) {
                // handle error
            }
            *i1 = create_intersection(&shape, distance.t[0]);
            *i2 = create_intersection(&shape, distance.t[1]);
            t_intersection **xs = malloc(sizeof(t_intersection *) * 2);
            if (xs == NULL) {
                // handle error
            }
            xs[0] = i1;
            xs[1] = i2;
            t_intersection **sorted_xs = sort_intersections(xs);
            t_intersection *hit = malloc(sizeof(t_intersection)); // allocate new memory for hit
            if (hit == NULL) {
                // handle error
            }
            *hit = *(sorted_xs[0]); // copy the intersection, don't just store the pointer
            if (hit->t > 0) {
                t_px_coord coord = {.x = x, .y = y, .rgb = rgb};
                supa_pixel_put(&img_vars, coord, rgb);
            } else {
                t_px_coord coord = {.x = x, .y = y, .rgb = black};
                supa_pixel_put(&img_vars, coord, black);
            }
            free(i1);
            free(i2);
            free(xs);
            free(sorted_xs);
            free(hit); // don't forget to free hit
            x++;
        }
        y++;
    }
	window_handle(&vars);
    put_image_to_window_vars(&vars);
    set_up_hooks(&vars);
    mlx_loop(vars.mlx_ptr);
    window_close(&vars);
}
*/