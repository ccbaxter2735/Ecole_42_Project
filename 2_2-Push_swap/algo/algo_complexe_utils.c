/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complexe_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:32:18 by terussar          #+#    #+#             */
/*   Updated: 2023/04/28 18:16:58 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*find_good_position(t_push *push, int **tab, int i, t_pile *first_b)
{
	t_pile	*first_a;

	first_a = push->pile_a;
	while (!(first_b->nb < first_a->nb && first_b->nb > first_a->prev->nb))
	{
		if (first_a->nb < first_b->nb)
		{
			first_a = first_a->next;
			tab[i][2]++;
		}
		else
		{
			first_a = first_a->prev;
			tab[i][3]--;
		}	
	}
	if (!(tab[i][2] == 0 && tab[i][3] == 0))
	{
		if (tab[i][2] != 0)
			tab[i][3] = -(lenght_pile_a(push) - tab[i][2]);
		else if (tab[i][3] != 0)
			tab[i][2] = lenght_pile_a(push) - tab[i][3];
	}
	return (tab[i]);
}

int	*create_cost_tab(t_push *push, int **tab, int i, t_pile *first_b)
{
	int	*tmp;

	tab[i][0] = i;
	tab[i][1] = -(lenght_pile_b(push) - i);
	tab[i][2] = 0;
	tab[i][3] = 0;
	find_good_position(push, tab, i, first_b);
	tmp = ft_min(ft_max(ft_abs(tab[i][0]), ft_abs(tab[i][2])),
			ft_max(ft_abs(tab[i][1]), ft_abs(tab[i][3])),
			ft_abs(tab[i][1]) + ft_abs(tab[i][2]),
			ft_abs(tab[i][0]) + ft_abs(tab[i][3]));
	tab[i][4] = tmp[0];
	tab[i][5] = tmp[1];
	free(tmp);
	return (tab[i]);
}

int	**move_cost(t_push *push)
{
	int		**tab;
	int		*cost_tab;
	int		i;
	t_pile	*first_b;

	i = 0;
	first_b = push->pile_b;
	tab = malloc(sizeof(int *) * lenght_pile_b(push));
	if (!tab)
		return (NULL);
	while (i < lenght_pile_b(push))
	{
		tab[i] = malloc(6 * sizeof(int));
		if (!tab[i])
			return (NULL);
		cost_tab = create_cost_tab(push, tab, i, first_b);
		first_b = first_b->next;
		i++;
	}
	return (tab);
}

int	find_min_cost(int **tab, t_push *push)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = i;
	min = tab[i][4];
	while (i < lenght_pile_b(push))
	{
		if (tab[i][4] < min)
		{
			min = tab[i][4];
			index = i;
		}
		i++;
	}
	return (index);
}
