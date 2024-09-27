/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:19:03 by terussar          #+#    #+#             */
/*   Updated: 2023/03/01 18:24:57 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_letter(char c)
{
	if (c == 's' || c == 'c' || c == 'i' || c == 'd'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	print_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_putstr(va_list parametre)
{
	char	*s;

	s = (char *) va_arg(parametre, char *);
	if (!s)
		return (write(1, "(null)", 6));
	return (ft_putstr2_fd(s, 1));
}

int	print_putnbr(va_list parametre)
{
	int	nb;
	int	lenght;

	nb = (int) va_arg(parametre, int);
	lenght = len((long)nb);
	ft_putnbr_fd(nb, 1);
	return (lenght);
}

int	print_put_unsignednbr(va_list parametre)
{
	unsigned int	nb;
	int				lenght;

	nb = (unsigned int) va_arg(parametre, unsigned int);
	lenght = len((long)nb);
	ft_putnbr_unsigned_fd(nb, 1);
	return (lenght);
}
