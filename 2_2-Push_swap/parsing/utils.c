/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:44:52 by terussar          #+#    #+#             */
/*   Updated: 2023/04/17 18:44:37 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (NULL);
}

void	*ft_instruction(char *str)
{
	write(1, str, ft_strlen(str));
	return (NULL);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
