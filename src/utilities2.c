/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:19:02 by chuleung          #+#    #+#             */
/*   Updated: 2024/07/25 20:29:46 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>>

void print_matrix(t_matrix_4x4 *mtx)
{
    printf("_________________\n");
    printf("{%f, %f, %f, %f}\n", mtx->entries[0][0],
        mtx->entries[0][1], mtx->entries[0][2], mtx->entries[0][3]);
    printf("{%f, %f, %f, %f}\n", mtx->entries[1][0],
        mtx->entries[1][1], mtx->entries[1][2], mtx->entries[1][3]);
    printf("{%f, %f, %f, %f}\n", mtx->entries[2][0],
        mtx->entries[2][1], mtx->entries[2][2], mtx->entries[2][3]);
    printf("{%f, %f, %f, %f}\n", mtx->entries[3][0],
        mtx->entries[3][1], mtx->entries[3][2], mtx->entries[3][3]);
    printf("_________________\n");
}
