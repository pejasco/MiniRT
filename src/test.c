/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 00:45:07 by chuleung          #+#    #+#             */
/*   Updated: 2024/08/03 18:55:02 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
    t_vars  vars;
    window_handle(&vars);


    



    put_image_to_window_vars(&vars);
    set_up_hooks(&vars);
    mlx_loop(vars.mlx_ptr);
    window_close(&vars);
}