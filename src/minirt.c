/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:29:43 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/23 17:53:44 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "mlx.h"
#include <X11/X.h>


int main(void)
{
	t_vars	vars;

	window_handle(&vars);
	
	//put_image_to_window_vars(&vars);
	set_up_hooks(&vars);
	mlx_loop(vars.mlx_ptr);
	window_close(&vars);
	return (0);
}