/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:35:02 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/03 16:54:57 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color create_color(double r, double g, double b)
{
    t_color result;

    result.r = r;
    result.g = g;
    result.b = b;
    return (result);
}

t_color add_colors(const t_color *a, const t_color *b)
{
    t_color result;

    result.r = a->r + b->r;
    result.g = a->g + b->g;
    result.b = a->b + a->b;
    return (result);
}

t_color subtract_colors(const t_color *original, const t_color *subtract)
{
    t_color result;

    result.r = original->r - subtract->r;
    result.g = original->g - subtract->g;
    result.b = original->b - subtract->b;
    return (result);
}

t_color multiply_colors(const t_color *a, const t_color *b)
{
    t_color result;

    result.r = a->r * b->r;
    result.g = a->g * b->g;
    result.b = a->b * b->b;
    return (result);
}
