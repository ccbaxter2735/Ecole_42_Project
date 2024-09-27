/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:00:09 by terussar          #+#    #+#             */
/*   Updated: 2023/04/28 18:18:38 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(int **tab, t_push *push)
{
	int	i;

	i = 0;
	while (i <= lenght_pile_b(push))
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	algo_100(t_push *push)
{
	int	nb_arg;
	int	**tab;
	int	index;
	int	i;

	nb_arg = push->pars.nb_arg;
	if (!(check_rank(push) == 0 && lenght_pile_a(push) == nb_arg))
	{
		first_sort(push, nb_arg);
		i = 0;
		while (i < (nb_arg - 2))
		{
			tab = move_cost(push);
			index = find_min_cost(tab, push);
			choose_case(push, tab, index);
			ft_push(&push->pile_b, &push->pile_a, "pa\n");
			free_tab(tab, push);
			i++;
		}
		final_rotation(push, nb_arg);
	}
}
