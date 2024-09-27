/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:04:26 by terussar          #+#    #+#             */
/*   Updated: 2024/09/28 00:19:20 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_letter(va_list parametre, char c)
{
	int	tmp;

	tmp = 0;
	if (c == 'c')
		tmp = print_putchar(va_arg(parametre, unsigned int));
	if (c == 's')
		tmp = print_putstr(parametre);
	if (c == 'i' || c == 'd')
		tmp = print_putnbr(parametre);
	if (c == 'u')
		tmp = print_put_unsignednbr(parametre);
	if (c == 'x')
		tmp = print_puthexa(parametre);
	if (c == 'X')
		tmp = print_puthexa_maj(parametre);
	if (c == 'p')
		tmp = print_putpointer(parametre);
	if (c == '%')
		tmp = write(1, "%", 1);
	return (tmp);
}

int	ft_printf(const char *arg, ...)
{
	va_list	parametre;
	int		compt;
	int		i;

	va_start (parametre, arg);
	i = 0;
	compt = 0;
	while (arg[i])
	{
		if (arg[i] == '%' && check_letter(arg[i + 1]) == 1)
		{
			compt += select_letter(parametre, arg[i + 1]);
			i++;
		}
		else
		{
			write(1, &arg[i], 1);
			compt++;
		}
		i++;
	}
	va_end(parametre);
	return (compt);
}
