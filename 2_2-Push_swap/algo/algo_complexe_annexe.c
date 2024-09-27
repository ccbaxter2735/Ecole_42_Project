/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe_annexe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:35:15 by terussar          #+#    #+#             */
/*   Updated: 2023/08/28 10:59:55 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// MARK : remet le plus petit nombre en haut de la pile
void	final_rotation(t_push *push, int nb_arg)
{
	while (!(push->pile_a->rank == 0))
	{
		if (push->pile_a->rank < (nb_arg / 2))
			ft_reverse_rotate(&push->pile_a, "rra\n");
		else
			ft_rotate(&push->pile_a, "ra\n");
	}
}

// MARK : envoie tous les nombres sur la pile b sauf max et min
void	first_sort(t_push *push, int nb_arg)
{
	int	cmpt;
	int	i;

	cmpt = push->pars.nb_arg;
	while (lenght_pile_a(push) != 2)
	{
		i = lenght_pile_a(push);
		cmpt /= 2;
		while (i > 0)
		{
			if (push->pile_a->rank == 0
				|| push->pile_a->rank == (nb_arg - 1)
				|| (push->pile_a->rank <= cmpt))
				ft_rotate(&push->pile_a, "ra\n");
			else
				ft_push(&push->pile_a, &push->pile_b, "pb\n");
			i--;
		}
	}
}
