/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_annexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:18:05 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 19:18:30 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_strerror(char *s)
{
	write(2, s, ft_strlen(s));
}

void	set_ret_val(t_vars *vars, int value)
{
	vars->ret_val = value;
}

void	msg_error(char *s, char *str)
{
	ft_strerror(s);
	ft_strerror(str);
	ft_strerror("\n");
}

int	ft_perror(char *s)
{
	perror(s);
	return (1);
}

// MARK : free **tab
void	free_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
