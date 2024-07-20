/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:58:37 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/11 18:41:08 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <strings.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*p;

	if (!n)
		return ;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/*int main(void)
{
	char str[] = "Keep pushing!!!";
	printf("%s\n", str);	
	//bzero(str, 17);
	//printf("%s\n", str);
	ft_bzero(str, 17);
	printf("%s\n", str);
	return (0);
}*/
