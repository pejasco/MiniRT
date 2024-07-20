/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:48:54 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/11 20:07:12 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	newlen;

	if (start >= ft_strlen(s) || len == 0)
		return ((char *)ft_calloc(1, 1));
	newlen = ft_strlen(&s[start]);
	if (newlen > len)
		newlen = len;
	newstr = (char *)malloc((newlen + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < newlen)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*int	main(void)
{
	int	start;
	size_t	len;

	start = 6;
	len = 5000000000;
	char const old[] = "abcdefghijk!";
	char *test = ft_substr(old, start, len);
	printf("%s\n", test);
	return (0);
}*/
/*
len6

012345
123456
*/
