/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:59:32 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/13 14:27:44 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

char	ft_toupperft(unsigned int index, char c)
{
	if (!(index % 2))
	{		
		if (c >= 'a' && c <= 'z')
			c -= 32;
		index++;
	}
	return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new;

	if (s == NULL || f == NULL)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	len = 0;
	while (s[len])
	{
		new[len] = s[len];
		len++;
	}
	new[len] = '\0';
	len = 0;
	while (new[len])
	{
		new[len] = f(len, new[len]);
		len++;
	}
	return (new);
}

/*int	main(void)
{
	char	*s;
	char	*test;

	s = "abcdefg!";
	test = ft_strmapi(s, ft_toupperft);
	printf("%s", test);
	return (0);
}*/
