/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:01:44 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 17:22:19 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_rr(t_push *push, int **tab, int index)
{
	while (tab[index][0] != 0 && tab[index][2] != 0)
	{
		ft_rotate_rr(push, "rr\n");
		tab[index][0]--;
		tab[index][2]--;
	}
	while (tab[index][0] != 0)
	{
		ft_rotate(&push->pile_b, "rb\n");
		tab[index][0]--;
	}
	while (tab[index][2] != 0)
	{
		ft_rotate(&push->pile_a, "ra\n");
		tab[index][2]--;
	}
}

void	case_rrr(t_push *push, int **tab, int index)
{
	while (tab[index][1] != 0 && tab[index][3] != 0)
	{
		ft_reverse_rotate_rrr(push, "rrr\n");
		tab[index][1]++;
		tab[index][3]++;
	}
	while (tab[index][1] != 0)
	{
		ft_reverse_rotate(&push->pile_b, "rrb\n");
		tab[index][1]++;
	}
	while (tab[index][3] != 0)
	{
		ft_reverse_rotate(&push->pile_a, "rra\n");
		tab[index][3]++;
	}
}

void	case_rrb_ra(t_push *push, int **tab, int index)
{
	while (tab[index][1] != 0)
	{
		ft_reverse_rotate(&push->pile_b, "rrb\n");
		tab[index][1]++;
	}
	while (tab[index][2] != 0)
	{
		ft_rotate(&push->pile_a, "ra\n");
		tab[index][2]--;
	}
}

void	case_rra_rb(t_push *push, int **tab, int index)
{
	while (tab[index][3] != 0)
	{
		ft_reverse_rotate(&push->pile_a, "rra\n");
		tab[index][3]++;
	}
	while (tab[index][0] != 0)
	{
		ft_rotate(&push->pile_b, "rb\n");
		tab[index][0]--;
	}
}

void	choose_case(t_push *push, int **tab, int index)
{
	if (tab[index][5] == 0)
		case_rr(push, tab, index);
	else if (tab[index][5] == 1)
		case_rrr(push, tab, index);
	else if (tab[index][5] == 2)
		case_rrb_ra(push, tab, index);
	else if (tab[index][5] == 3)
		case_rra_rb(push, tab, index);
}
