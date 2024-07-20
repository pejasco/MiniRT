/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:28:49 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/14 15:24:37 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;	

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*int	main(void)
{
	int	i;
	int	j;

	char s1[20] = "I am a hand";
	char s2[20] = "I am a hande";
	i = strncmp(s1, s2, 20);
	j = ft_strncmp(s1, s2, 20);	
	printf("%d\n", i);
	printf("%d\n", j);
	return (0);
}*/
