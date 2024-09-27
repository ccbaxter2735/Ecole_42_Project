/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:36:23 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 16:30:41 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_push	push;
	int		i;

	i = 0;
	ft_bzero(&push, sizeof(t_push));
	if (ac > 1 && av[1][0] != 0)
	{
		if (parsing(0, av, ac, &push) == 0)
		{
			if (push.pars.nb_arg <= 3)
				algo_3(&push);
			else if (push.pars.nb_arg <= 4)
				algo_4(&push);
			else if (push.pars.nb_arg <= 5)
				algo_5(&push);
			else
				algo_100(&push);
		}
	}
	free(push.pars.sort_tab);
	free(push.pars.tab_int);
	clean(&push.pile_a);
	return (0);
}
