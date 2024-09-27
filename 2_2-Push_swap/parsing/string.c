/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:16 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 17:13:27 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// MARK : free les tableaux d arguments et d arguments tries
void	clean(t_pile **pile)
{
	t_pile	*elem;
	t_pile	*tmp;

	elem = *pile;
	if (elem == NULL)
		return ;
	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		free(tmp);
		if (elem == *pile)
			break ;
	}
}

// MARK : cree une liste chaine circulaire
int	create_boucle(t_push *push)
{
	t_pile	*old;
	t_pile	*first;

	old = push->pile_a;
	first = push->pile_a;
	while (old)
	{
		if (!old->next)
		{
			old->next = first;
			first->prev = old;
			break ;
		}
		old = old->next;
	}
	return (0);
}

// MARK : cree la pile en ecrivant le nb et son rank
t_pile	*t_pile_new(int nbr, t_push *push)
{
	t_pile	*p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new != NULL)
	{
		p_new->nb = nbr;
		p_new->rank = find_rank(nbr, &push->pars);
		p_new->prev = NULL;
		p_new->next = NULL;
	}
	return (p_new);
}

// MARK : lie les piles entre elles pour creer le chainage
int	t_pile_append(t_push *push)
{
	t_pile	*old;
	t_pile	*new;
	int		i;

	i = 0;
	old = NULL;
	while (i < push->pars.nb_arg)
	{
		new = t_pile_new(push->pars.tab_int[i], push);
		if (!new)
			return (1);
		if (!push->pile_a)
			push->pile_a = new;
		if (old != NULL)
		{
			old->next = new;
			new->prev = old;
		}
		old = new;
		i++;
	}
	create_boucle(push);
	return (0);
}

// void	print_pile(t_pile *pile)
// {
// 	ft_printf("  ---------------------------\n");
// 	ft_printf("|    value : %d\n", pile->nb);
// 	ft_printf("|     rank : %d\n", pile->rank);
// 	ft_printf("|     adr  : %p\n", pile);
// 	ft_printf("| previous : %p\n", pile->prev);
// 	ft_printf("|     next : %p\n", pile->next);
// 	ft_printf("| \n");
// 	ft_printf("\n");
// }

// void	vizualize_a(t_push *push)
// {
// 	t_pile	*old;

// 	old = push->pile_a;
// 	if (old)
// 	{
// 		while (1)
// 		{
// 			print_pile(old);
// 			old = old->next;
// 			if (old == push->pile_a)
// 				break ;
// 		}
// 	}
// }

// void	vizualize_b(t_push *push)
// {
// 	t_pile	*old;

// 	old = push->pile_b;
// 	if (old)
// 	{
// 		while (1)
// 		{
// 			print_pile(old);
// 			old = old->next;
// 			if (old == push->pile_b)
// 				break ;
// 		}
// 	}
// }
