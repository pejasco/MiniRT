/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tupes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:23:46 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/20 22:17:32 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple create_tuples(double x, double y, double z, t_tuple_type type)
{
    t_tuple     tuple;
    
    tuple.x = x;
    tuple.y = y;
    tuple.z = z;
    tuple.type = type;
    return (tuple);
}

t_tuple add_tuples(t_tuple a, t_tuple b)
{
    t_tuple    addition;

    addition.x = a.x + b.x;
    addition.y = a.y + b.y;
    addition.z = a.z + b.z;
    if (a.type == Point  && b.type == Point)
    {
        perror("2 points cannot be added together");
        exit(1);
    }
    else if ((a.type == Point && b.type == Vector)
            || (a.type == Vector && b.type == Point))
        addition.type = Point;
    else 
        addition.type = Vector;
    return (addition);
}

t_tuple substrct_tuples(t_tuple a, t_tuple b)
{
    t_tuple addition;

    if (a.type == Point  && b.type == Point)
    {
        perror("2 points cannot be subtracted");
        exit(1);
    }
    else if (a.type == Vector && b.type == Point)
    {
        addition.x = b.x - a.x;
        addition.y = b.y - a.y;
        addition.z = b.z - a.z;
        addition.type = Point;
    }
    else
    {
        addition.x = a.x - b.x;
        addition.y = a.y - b.y;
        addition.z = a.z - b.z;
        addition.type = Vector;
        if (a.type == Point && b.type == Vector)
            addition.type = Point;
    }
    return addition;
}


t_tuple negate_tuples(t_tuple a, t_tuple b)
{
    t_tuple     subtract;

    subtract.x     



}
