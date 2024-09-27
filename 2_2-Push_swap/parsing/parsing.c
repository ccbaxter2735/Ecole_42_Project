/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:11:12 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:33 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// MARK : verifie les doublons dans liste int triee
int	check_double(t_pars *pars)
{
	int	i;

	i = 0;
	while (i < pars->nb_arg - 1)
	{
		if (pars->sort_tab[i] == pars->sort_tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

// MARK : trouve le rank d un nb dans la liste triee
int	find_rank(int nb, t_pars *pars)
{
	int	i;

	i = 0;
	while (i < pars->nb_arg)
	{
		if (pars->sort_tab[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

// MARK : fct annexe de check_argument
int	test_arg(char **str, int j)
{
	char	*nb;

	nb = ft_itoa(ft_atoi(str[j]));
	if (ft_strncmp(str[j], nb, ft_strlen(str[j])) != 0)
	{
		free(str[j]);
		free(nb);
		free (str);
		return (1);
	}
	free(str[j]);
	free(nb);
	return (0);
}

// MARK : verifie que les arguments sont des nombres et int
int	check_argument(char **arg, int ac, t_pars *pars)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (i < ac)
	{
		j = 0;
		str = ft_split(arg[i], ' ');
		while (str[j])
		{
			if (test_arg(str, j) == 1)
				return (1);
			pars->nb_arg++;
			j++;
		}
		free(str);
		i++;
	}
	return (0);
}

//MARK : execute les verif sur les arguments
int	parsing(int i, char **av, int ac, t_push *push)
{
	if (check_argument(av, ac, &push->pars) == 1)
	{
		if (i == 0)
			ft_error("Error\n");
		return (1);
	}
	create_list_int(av, ac, &push->pars);
	ft_nbdup(&push->pars);
	sort_list(&push->pars, 0, push->pars.nb_arg - 1);
	if (check_double(&push->pars) == 1)
	{
		if (i == 0)
			ft_error("Error\n");
		return (1);
	}
	t_pile_append(push);
	push->pile_b = NULL;
	return (0);
}
// ft_printf("--------- Pile A -------\n");
// vizualize_a(&push);
// ft_printf("--------- Pile B -------\n");
// vizualize_b(&push);
