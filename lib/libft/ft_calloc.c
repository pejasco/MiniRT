/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:15:04 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/13 19:19:33 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ary;
	size_t	i;
	size_t	bsize;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	bsize = nmemb * size;
	if (bsize < nmemb || bsize < size)
		return (NULL);
	ary = (char *)malloc(bsize);
	if (ary == NULL)
		return (NULL);
	i = 0;
	while (i < bsize)
		ary[i++] = 0;
	return ((void *)ary);
}
