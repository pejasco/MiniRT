/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:29:06 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/04 20:29:09 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && big[i + j]
			&& i + j < len)
			j++;
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
//#include <stdio.h>
//#include <string.h>

/*int	main(void)
{
	const char	*big = "abcdefghi";
	const char	*little = "def";
	int len = 5;

	char	*mine = ft_strnstr(big, little, len);
	char	*linux = strnstr(big, little, len);

	printf
	(
		"big:           {%s}\n"
		"little:        {%s}\n\n", big, little
	);
	printf("Linux:{%s}\n", linux);
	printf("Mine :{%s}\n", mine); 	
}*/
