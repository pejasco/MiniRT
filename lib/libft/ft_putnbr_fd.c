/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:02:45 by chuleung          #+#    #+#             */
/*   Updated: 2023/11/14 15:25:25 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <limits.h>

static int	my_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n / 10 == 0)
	{
		ft_putchar_fd((my_abs(n) + '0'), fd);
	}
	else
	{
		ft_putnbr_fd(my_abs(n / 10), fd);
		ft_putnbr_fd(my_abs(n % 10), fd);
	}
}

/*int	main(void)
{
	int test;
	int	fd;

	
	fd = 1;
	//test = INT_MIN;
	test = INT_MAX;

	ft_putnbr_fd(test, fd);
	return (0);
}*/
