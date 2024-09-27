/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:50:16 by terussar          #+#    #+#             */
/*   Updated: 2023/04/28 10:25:56 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_rank(t_push	*push)
{
	t_pile	*first;

	first = push->pile_a;
	if (first)
	{
		while (1)
		{
			if (first->rank > first->next->rank)
				return (1);
			first = first->next;
			if (first->next == push->pile_a)
				break ;
		}
	}
	return (0);
}

int	lenght_pile_a(t_push	*push)
{
	t_pile	*first;
	int		compt;

	first = push->pile_a;
	compt = 0;
	if (first)
	{
		compt++;
		while (1)
		{
			first = first->next;
			compt++;
			if (first->next == push->pile_a)
				break ;
		}
	}
	return (compt);
}

int	lenght_pile_b(t_push	*push)
{
	int		compt;

	compt = push->pars.nb_arg - lenght_pile_a(push);
	return (compt);
}

int	max_rank_pile(t_push *push)
{
	t_pile	*first;
	int		max;

	first = push->pile_a;
	max = first->rank;
	if (first)
	{
		while (1)
		{
			first = first->next;
			if (first->rank > max)
				max = first->rank;
			if (first->next == push->pile_a)
				break ;
		}
	}
	return (max);
}

int	min_rank_pile(t_push *push)
{
	t_pile	*first;
	int		min;

	first = push->pile_a;
	min = first->rank;
	if (first)
	{
		while (1)
		{
			first = first->next;
			if (first->rank < min)
				min = first->rank;
			if (first->next == push->pile_a)
				break ;
		}
	}
	return (min);
}
