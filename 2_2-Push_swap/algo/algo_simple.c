/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:00:19 by terussar          #+#    #+#             */
/*   Updated: 2023/04/28 10:18:29 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_3(t_push	*push)
{
	int	max;
	int	min;

	max = max_rank_pile(push);
	min = min_rank_pile(push);
	while (check_rank(push) != 0)
	{
		if (push->pile_a->rank == max)
			ft_rotate(&push->pile_a, "ra\n");
		else if (push->pile_a->next->rank == max)
			ft_reverse_rotate(&push->pile_a, "rra\n");
		else if (push->pile_a->rank != max && push->pile_a->next->rank == min)
			ft_swap(push->pile_a, "sa\n");
	}
}

void	algo_4(t_push *push)
{
	int	max;
	int	min;

	max = max_rank_pile(push);
	min = min_rank_pile(push);
	while (!(check_rank(push) == 0 && lenght_pile_a(push) == 4))
	{
		if (lenght_pile_a(push) == 4 && push->pile_a->rank == min)
			ft_push(&push->pile_a, &push->pile_b, "pb\n");
		else if (push->pile_a->next->rank == min)
			ft_swap(push->pile_a, "sa\n");
		else if (push->pile_a->prev->rank == min)
			ft_rotate(&push->pile_a, "ra\n");
		else if (lenght_pile_a(push) == 3 && check_rank(push) == 0)
			ft_push(&push->pile_b, &push->pile_a, "pa\n");
		else if (lenght_pile_a(push) == 3 && check_rank(push) != 0)
			algo_3(push);
		else
			ft_rotate(&push->pile_a, "ra\n");
	}
}

void	algo_5(t_push *push)
{
	int	max;

	max = max_rank_pile(push);
	while (!(check_rank(push) == 0 && lenght_pile_a(push) == 5))
	{
		if (lenght_pile_a(push) == 5 && push->pile_a->rank == 0)
			ft_push(&push->pile_a, &push->pile_b, "pb\n");
		else if (push->pile_a->next->rank == 0)
			ft_swap(push->pile_a, "sa\n");
		else if (push->pile_a->prev->rank == 0)
			ft_reverse_rotate(&push->pile_a, "rra\n");
		else if (lenght_pile_a(push) == 4 && check_rank(push) == 0)
			ft_push(&push->pile_b, &push->pile_a, "pa\n");
		else if (lenght_pile_a(push) == 4 && check_rank(push) != 0)
			algo_4(push);
		else
			ft_rotate(&push->pile_a, "ra\n");
	}
}
