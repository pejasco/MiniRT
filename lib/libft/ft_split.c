/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:12:10 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/13 19:38:25 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdlib.h>

static size_t	nr_of_arrays(char const *s, char d)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (s[i])
	{
		while (s[i] == d)
			i++;
		if (s[i] != d && s[i])
			sum++;
		while (s[i] != d && s[i])
			i++;
	}
	return (sum);
}

static char	*extract_str(char const *s, char c)
{
	char	*out_str;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	out_str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[i] != c && i < len)
	{
		out_str[i] = s[i];
		i++;
	}
	out_str[i] = '\0';
	return (out_str);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		total;
	char		**strs;

	i = 0;
	j = 0;
	total = nr_of_arrays(s, c);
	strs = (char **)malloc(sizeof(char *) * (total + 1));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			strs[j] = extract_str(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

/*#include <stdio.h>

int	main(void)
{
	char *s = "021";
	char c = '2';
	char **output;

	output = ft_split(s, c);
	for (int i = 0; output[i] != NULL; i++)
		printf("%s\n", output[i]);
	return (0);
}*/
