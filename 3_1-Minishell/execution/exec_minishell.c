/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:56:56 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 14:43:08 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_minishell(t_parse *pars, t_vars *vars)
{
	while (pars != NULL)
	{
		if (pars->nature != 0)
		{
			if (pars->nature == 1)
			{
				if (redirect(pars) == 1)
					return ;
			}
			else if (pars->nature == 2 && pars->way == 1)
				append(pars);
			else if (pars->nature == 2 && pars->way == 0)
				heredoc(pars, vars);
		}
		if (pars->nature == 0)
			exec_fct(pars, vars);
		pars = pars->next;
	}
}

// MARK : execute all the line of the parsing fct
void	exec_redir(t_parse *pars, t_vars *vars)
{
	while (pars != NULL)
	{
		if (pars->nature == 1)
		{
			if (redirect(pars) == 1)
				return ;
		}
		else if (pars->nature == 2 && pars->way == 1)
			append(pars);
		else if (pars->nature == 2 && pars->way == 0)
			heredoc(pars, vars);
		pars = pars->next;
	}
}

void	exec_function(t_parse *pars, t_vars *vars)
{
	while (pars != NULL)
	{
		if (pars->nature == 0)
			exec_fct(pars, vars);
		pars = pars->next;
	}
}

char	*ft_readline(t_vars *vars)
{
	char	*str;

	ft_putstr_fd(ft_prompt(vars), 1);
	str = get_next_line(STDIN_FILENO);
	return (str);
}

// MARK : loop prompt
void	loop_prompt(t_vars *vars)
{
	char	*tmp;
	int		pid;
	int		i;

	tmp = readline(ft_prompt(vars));
	while (tmp)
	{
		if (!parsing(tmp, vars))
		{
			i = ft_tab_len(vars->tab_t_parse);
			if (i == 1 && !is_built_in(*vars->tab_t_parse, vars, 0))
				is_built_in(*vars->tab_t_parse, vars, 1);
			else
			{
				pid = fork();
				if (i == 1 && !pid)
					exec_minishell(*vars->tab_t_parse, vars);
				else if (!pid)
					exec_multipipe(vars, ft_tab_len(vars->tab_t_parse));
				parent_act(pid, vars);
			}
		}
		init_sigs_interact(vars);
		tmp = readline(ft_prompt(vars));
	}
}
