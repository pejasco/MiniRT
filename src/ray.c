/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:22:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/31 13:54:48 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rotate->scale->translate

#include <stdbool.h>
#include "minirt.h"
#include <stdio.h>
#include <assert.h>

t_tuple position(t_ray *ray, double speed)
{
    t_tuple scale;

    scale = scale_tuple(&(ray->vector), speed);
    return (add_tuples(&(ray->origin_point), &scale));
}



