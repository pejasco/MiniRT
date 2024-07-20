/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:26:03 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/11 19:33:24 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include <stdio.h>
//include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = c;
	return (s);
}
/*int main(void)
{
    char str[20];
    strcpy(str, "Keep pushing!!!!!!");
    printf("%s\n", str);
    ft_memset(str, '$', 8);   
    printf("%s", str);
    return (0);
}*/
