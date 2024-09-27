/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xXp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:18:59 by terussar          #+#    #+#             */
/*   Updated: 2022/12/14 19:33:16 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_puthexa(va_list parametre)
{
	unsigned int	nb;
	int				lenght;

	nb = (unsigned int) va_arg(parametre, unsigned int);
	lenght = ft_lenhexa(nb);
	ft_puthexa(nb);
	return (lenght);
}

int	print_puthexa_maj(va_list parametre)
{
	unsigned int	nb;
	int				lenght;

	nb = (unsigned int) va_arg(parametre, unsigned int);
	lenght = ft_lenhexa(nb);
	ft_puthexa_maj(nb);
	return (lenght);
}

int	print_putpointer(va_list parametre)
{
	unsigned long	p;
	int				lenght;

	p = (unsigned long) va_arg(parametre, unsigned long);
	if (!p)
		return (write(1, "(nil)", 5));
	lenght = ft_lenhexa(p) + 2;
	write(1, "0x", 2);
	ft_puthexa(p);
	return (lenght);
}

// int main()
// {
// 	unsigned int	i;

// 	i = 12333365;
// 	printf("%d\n", ft_puthexa_maj(i));
// }