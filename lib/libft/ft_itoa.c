/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:57:19 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/14 15:26:59 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>

static size_t	*re_itoa(long num, char *ary)
{
	static size_t	j = 0;

	if (ary[j] == '-')
		j++;
	if (num / 10 == 0)
		ary[j++] = num + '0';
	else
	{
		re_itoa(num / 10, ary);
		ary[j++] = num % 10 + '0';
	}
	return (&j);
}

char	*ft_itoa(int n)
{
	int		i;
	char	ary[40];
	char	*out;
	long	num;
	size_t	*j;

	i = 0;
	while (i < 40)
		ary[i++] = '\0';
	num = n;
	if (num < 0)
	{
		num = -num;
		ary[0] = '-';
	}
	j = re_itoa(num, ary);
	*j = 0;
	out = (char *)malloc((ft_strlen(ary) +1) * sizeof(char));
	ft_strlcpy(out, ary, (ft_strlen(ary) + 1));
	return (out);
}
/*int	main(void)
{
	long	nbr;
	char *test;

	nbr = 2147483647;
	test = ft_itoa(nbr);
	printf("%s\n", test);
	//write(1, &test[1], 1);
	return (0);
}*/
