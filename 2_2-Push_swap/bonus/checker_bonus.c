/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:21:08 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 16:59:38 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_checker(t_push *push)
{
	free(push->pars.sort_tab);
	free(push->pars.tab_int);
	clean(&push->pile_a);
}

void	checker_validation(t_push *push)
{
	if (check_rank(push) == 0 && push->pile_b == 0)
		ft_instruction("OK\n");
	else
		ft_instruction("KO\n");
}

void	check_str(char *str, t_push *push)
{
	if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		ft_rotate(&push->pile_a, "");
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		ft_rotate(&push->pile_b, "");
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		ft_reverse_rotate(&push->pile_a, "");
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		ft_reverse_rotate(&push->pile_b, "");
	else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		ft_swap(push->pile_a, "");
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		ft_swap(push->pile_b, "");
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		ft_push(&push->pile_b, &push->pile_a, "");
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		ft_push(&push->pile_a, &push->pile_b, "");
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		ft_rotate_rr(push, "");
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		ft_reverse_rotate_rrr(push, "");
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		ft_swap_ss(push, "");
}

int	boucle_str(char *str, t_push *push)
{
	if ((str))
		check_str(str, push);
	else
	{
		ft_error("Error\n");
		free(str);
		free_checker(push);
		return (1);
	}
	free(str);
	return (0);
}

int	main(int ac, char **av)
{
	t_push	push;
	int		i;
	char	*str;

	i = 0;
	ft_bzero(&push, sizeof(t_push));
	if (ac > 1 && av[1][0] != 0)
	{
		if (parsing(1, av, ac, &push) == 0)
		{
			str = get_next_line(0);
			while ((str))
			{
				if (boucle_str(str, &push) == 1)
					return (0);
				str = get_next_line(0);
			}
			checker_validation(&push);
		}
	}
	free_checker(&push);
	return (0);
}
