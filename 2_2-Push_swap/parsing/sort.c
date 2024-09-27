/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:22 by terussar          #+#    #+#             */
/*   Updated: 2023/05/04 14:34:13 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// MARK : convertie les arg char ** en int *
int	*create_list_int(char **arg, int ac, t_pars *pars)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 1;
	k = 0;
	pars->tab_int = malloc(sizeof(int) * (pars->nb_arg));
	if (!pars->tab_int)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		str = ft_split(arg[i], ' ');
		while (str[j])
		{
			pars->tab_int[k++] = ft_atoi(str[j]);
			free(str[j]);
			j++;
		}
		free(str);
		i++;
	}
	return (pars->tab_int);
}

void	swap_tab(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_nbdup(t_pars *pars)
{
	int	i;

	pars->sort_tab = malloc(sizeof(int) * (pars->nb_arg));
	if (!pars->sort_tab)
		return (NULL);
	i = 0;
	while (i < pars->nb_arg)
	{
		pars->sort_tab[i] = pars->tab_int[i];
		i++;
	}
	return (pars->sort_tab);
}

int	*sort_list(t_pars *pars, int first, int last)
{
	int	pivot;
	int	i;
	int	j;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (pars->sort_tab[i] <= pars->sort_tab[pivot] && i < last)
				i++;
			while (pars->sort_tab[j] > pars->sort_tab[pivot])
				j--;
			if (i < j)
				swap_tab(&pars->sort_tab[i], &pars->sort_tab[j]);
		}
		swap_tab(&pars->sort_tab[pivot], &pars->sort_tab[j]);
		sort_list(pars, first, j - 1);
		sort_list(pars, j + 1, last);
	}
	return (pars->sort_tab);
}
