/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:45:07 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/05 22:40:30 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>

t_intersect_pts sphere_intersec_pts(t_sphere *s, t_ray *r) {
    t_intersect_pts intersect_pts;
    t_sphere_intersec_vars vars;
    t_tuple sphere_to_ray;
    
    sphere_to_ray = point_minus_point(&r->origin_point, &s->origin_point);
    vars.a = dot_product(&r->vector, &r->vector);
    vars.b = 2 * dot_product(&r->vector, &sphere_to_ray);
    vars.c = dot_product(&sphere_to_ray, &sphere_to_ray) - 1;
    vars.discriminant = vars.b * vars.b - 4 * vars.a * vars.c;

    intersect_pts.count = 0;
    if (vars.discriminant >= 0) {
        intersect_pts.count = 2;
        intersect_pts.intersec_1.x = (-vars.b - sqrt(vars.discriminant)) / (2 * vars.a);
        intersect_pts.intersec_2.x = (-vars.b + sqrt(vars.discriminant)) / (2 * vars.a);
        intersect_pts.intersec_1.w = intersect_pts.intersec_2.w = 1.0;
    }
    return intersect_pts;
}

void draw_sphere(t_img *img_vars) {
    t_ray ray;
    t_sphere sphere;
    t_intersect_pts intersect_pts;
    int canvas_pixels = 100;
    double wall_size = 7.0;
    double pixel_size = wall_size / canvas_pixels;
    double half = wall_size / 2.0;
    int x, y;
    t_px_coord px_coord;

    // Initialize the sphere
    sphere = create_sphere(1, create_tuple(0, 0, 0, Point));
    ray = create_ray(create_tuple(0, 0, -5, Point), create_tuple(0, 0, 1, Vector));

    // Draw the canvas
    for (y = 0; y < canvas_pixels; y++) {
        for (x = 0; x < canvas_pixels; x++) {
            double world_x = -half + pixel_size * x;
            double world_y = half - pixel_size * y;
            t_tuple pixel_position = create_tuple(world_x, world_y, 10, Point);
            t_tuple ray_direction = normalize_vector(&pixel_position, find_magnitude(&pixel_position));
            ray.vector = ray_direction;
            intersect_pts = sphere_intersec_pts(&sphere, &ray);

            // If the sphere is hit, color the pixel
            if (intersect_pts.count > 0) {
                px_coord.x = WIDTH / 2 + (x - canvas_pixels / 2) * (WIDTH / canvas_pixels);
                px_coord.y = HEIGHT / 2 - (y - canvas_pixels / 2) * (HEIGHT / canvas_pixels); // Flip y-axis for image
                px_coord.rgb = RED; // Color the pixel red if the sphere is hit
                supa_pixel_put(img_vars, px_coord, px_coord.rgb);
            }
        }
    }
}

int main() {
    t_vars vars;

    window_handle(&vars);
    draw_sphere(&vars.img_vars);
    mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img_vars.img_ptr, 0, 0);
    mlx_loop(vars.mlx_ptr);

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