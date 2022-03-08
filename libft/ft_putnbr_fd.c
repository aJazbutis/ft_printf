/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajazbuti <ajazbuti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:07:11 by ajazbuti          #+#    #+#             */
/*   Updated: 2021/09/22 18:41:16 by ajazbuti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(int n, int fd)
{
	int	m;

	m = n % 10 + '0';
	if (n == 0)
		return (m);
	else
	{
		m = n % 10 + '0';
		ft_putnbr(n / 10, fd);
		write(fd, &m, 1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MAX)
		write(fd, "2147483647", 10);
	else if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * (-1);
		}
		ft_putnbr(n, fd);
	}
}
