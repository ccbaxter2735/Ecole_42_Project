/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:46:24 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 21:01:56 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	int	ft_unset_err(t_parse *pars, t_vars *vars)
{
	if (ft_strlen(pars->cmd_arg) > 5)
	{
		if (pars->cmd_arg[5] == ' ' && is_options(pars->cmd_arg + 5))
			return (set_ret_val(vars, 2), ft_strerror
				("minishell: unset does not take option\n"), 0);
		if (pars->cmd_arg[5] != ' ')
			return (msg_error("minishell: command not found: ", pars->cmd_arg),
				set_ret_val(vars, 127), 0);
	}
	return (1);
}

static char	**get_args(t_parse *pars, t_vars *vars, int *i)
{
	char	**tab;

	tab = NULL;
	pars->cmd_arg = erase_quote(pars->cmd_arg);
	tab = ft_split_wsp(pars->cmd_arg, i, vars);
	free(pars->cmd_arg);
	return (tab);
}

int	exec_unset(t_parse *pars, t_vars *vars, int go)
{
	char	**tab;
	int		i[2];
	int		n;
	char	*here;

	if (ft_strncmp(pars->cmd_arg, "unset", 5) == 0)
	{
		if (!go || !ft_unset_err(pars, vars))
			return (0);
		i[1] = unset_index;
		ft_init_vars(&(i[0]), NULL, &n, NULL);
		tab = get_args(pars, vars, i);
		if (len_tab(tab) < 2)
			return (vars->ret_val = 0, 0);
		while (tab[++n])
		{
			here = get_env(ft_strjoin_gc(tab[n], "=", vars, i), vars);
			if (here)
				vars->env_shell = ft_env_del(vars->env_shell,
						ft_strjoin_gc(tab[n], "=", vars, i), vars);
		}
		gc_del(vars->list_gc, UNUSED, unset_index, NULL);
		return (vars->ret_val = 0, 0);
	}
	return (1);
}
