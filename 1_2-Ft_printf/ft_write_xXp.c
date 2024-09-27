/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_xXp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:24:02 by terussar          #+#    #+#             */
/*   Updated: 2022/12/14 19:34:25 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nb)
{
	char			*base;
	unsigned long	n;
	int				i;

	n = nb;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		ft_puthexa(nb / 16);
		ft_putchar_fd(base[nb % 16], 1);
	}
	else
		ft_putchar_fd(base[nb % 16], 1);
	i = ft_lenhexa(n);
	return (i);
}

int	ft_puthexa_maj(unsigned long nb)
{
	char			*base;
	unsigned long	n;
	int				i;

	n = nb;
	base = "0123456789ABCDEF";
	if (nb > 15)
	{
		ft_puthexa_maj(nb / 16);
		ft_putchar_fd(base[nb % 16], 1);
	}
	else
		ft_putchar_fd(base[nb % 16], 1);
	i = ft_lenhexa(n);
	return (i);
}

// int main()
// {
// //	int	i;

// 	//i = 4294967295;
// //printf("%x", 429496729);
// //	printf("\n");
// 	//ft_printf("%x", 429496729);
// 	// printf("%ld \n", LONG_MAX);
// 	printf("%ld", LONG_MIN);
// 	printf("%d", printf("%lx", LONG_MIN));
// }
