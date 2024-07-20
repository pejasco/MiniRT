/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:22:24 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/14 15:25:02 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	res1;
	int res2;

	char s1[20] = "Iamahandsomeman";
	char s2[20] = "Iamahandsomeman";
	res1 = memcmp(s1, s2, 4);
	res2 = ft_memcmp(s1, s2, 4);	
	printf("%d\n", res1);
	printf("%d\n", res2);
	return (0);
}
*/
