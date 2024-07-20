/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:20:36 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/11 19:45:34 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	character;

	ptr = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == character)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	c;
	char	*org;
	char	*res;	

	c = 'a';
	char str[15] = "iamhandsomeha!";

	org = memchr(str, c, 20);
	res = ft_memchr(str, c, 20);
	printf("%s\n", org);
	printf("%s\n", res);
	printf("%p\n", org);
	printf("%p\n", res);
}*/
