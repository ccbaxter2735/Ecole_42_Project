/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:25:24 by terussar          #+#    #+#             */
/*   Updated: 2023/04/30 21:47:55 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// MARK : renvoi le minimum de 4 nb et sa position
int	*ft_min(int a, int b, int c, int d)
{
	int	*min;

	min = malloc(sizeof(int) * 2);
	if (!min)
		return (NULL);
	min[0] = a;
	min[1] = 0;
	if (b < min[0])
	{
		min[0] = b;
		min[1] = 1;
	}
	if (c < min[0])
	{
		min[0] = c;
		min[1] = 2;
	}
	if (d < min[0])
	{
		min[0] = d;
		min[1] = 3;
	}
	return (min);
}

// MARK : renvoi le max
int	ft_max(int a, int b)
{
	int	max;

	max = a;
	if (b > max)
		max = b;
	return (max);
}
