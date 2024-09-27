/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_csiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:26:54 by terussar          #+#    #+#             */
/*   Updated: 2023/03/01 18:12:03 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar2_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr2_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar2_fd('-', fd);
		ft_putchar2_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar2_fd('-', fd);
		nb = nb * (-1);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar2_fd('0' + (nb % 10), fd);
	}
	else
		ft_putchar2_fd('0' + nb, fd);
}

void	ft_putnbr_unsigned_fd(unsigned int nb, int fd)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned_fd(nb / 10, fd);
		ft_putchar2_fd('0' + (nb % 10), fd);
	}
	else
		ft_putchar2_fd('0' + nb, fd);
}
