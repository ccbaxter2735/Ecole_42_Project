/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_swap_push_rot_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:30:07 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 17:02:29 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rotate_rr(t_push *push, char *inst)
{
	ft_rotate(&push->pile_a, "");
	ft_rotate(&push->pile_b, "");
	ft_instruction(inst);
	return (0);
}

int	ft_reverse_rotate_rrr(t_push *push, char *inst)
{
	ft_reverse_rotate(&push->pile_a, "");
	ft_reverse_rotate(&push->pile_b, "");
	ft_instruction(inst);
	return (0);
}

int	ft_swap_ss(t_push *push, char *inst)
{
	ft_swap(push->pile_a, "");
	ft_swap(push->pile_b, "");
	ft_instruction(inst);
	return (0);
}
