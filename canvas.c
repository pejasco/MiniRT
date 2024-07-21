/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:14:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/21 18:26:56 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas create_canvas(int width, int height)
{
    t_canvas canvas;

    canvas.width = width;
    canvas.height = height;
    return (canvas);
}