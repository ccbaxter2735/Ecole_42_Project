/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_swap_push_rot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:54:03 by terussar          #+#    #+#             */
/*   Updated: 2023/04/28 10:17:32 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// swap : Intervertit les 2 premiers éléments au sommet de la pile
// push (Pa): Prend le premier élément au sommet de b et le met sur a
// rotate : Le dernier élément devient le premier

int	ft_swap(t_pile	*top, char *inst)
{
	int	tmp;

	tmp = top->nb;
	top->nb = top->next->nb;
	top->next->nb = tmp;
	tmp = top->rank;
	top->rank = top->next->rank;
	top->next->rank = tmp;
	ft_instruction(inst);
	return (0);
}

int	ft_reverse_rotate(t_pile	**top, char *inst)
{
	t_pile	*first;

	first = *top;
	first = first->prev;
	*top = first;
	ft_instruction(inst);
	return (0);
}

int	ft_rotate(t_pile	**top, char *inst)
{
	t_pile	*first;

	first = *top;
	first = first->next;
	*top = first;
	ft_instruction(inst);
	return (0);
}

void	erase_first(t_pile	**from)
{
	t_pile	*first;
	t_pile	*tmp;

	first = *from;
	tmp = first->next;
	if (first->next != first)
	{
		first->prev->next = first->next;
		first->next->prev = first->prev;
		*from = tmp;
	}
	else
		*from = NULL;
}

int	ft_push(t_pile **from, t_pile **to, char *inst)
{
	t_pile	*first_from;
	t_pile	*first_to;

	first_from = *from;
	if (first_from != NULL)
	{
		erase_first(from);
		if (*to != NULL)
		{
			first_to = *to;
			first_to->prev->next = first_from;
			first_from->prev = first_to->prev;
			first_from->next = first_to;
			first_from->next->prev = first_from;
			*to = first_from;
		}
		else
		{
			*to = first_from;
			first_from->next = *to;
			first_from->prev = *to;
		}
		ft_instruction(inst);
	}
	return (0);
}
