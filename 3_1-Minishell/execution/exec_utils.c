/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:39:08 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 15:06:13 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_tab_len(t_parse **tab_parse)
{
	int	i;

	i = 0;
	while (tab_parse && tab_parse[i])
		i++;
	return (i);
}

int	is_built_in(t_parse *pars, t_vars *vars, int go)
{
	int		save_fd[2];
	int		ret;

	vars->fd_dup = save_fd;
	if (go != 0)
	{
		save_fd[0] = dup(0);
		save_fd[1] = dup(1);
		exec_redir(pars, vars);
	}
	while (pars && pars->nature != 0)
		pars = pars->next;
	if (!pars)
		return (1);
	ret = exec_built_in(pars, vars, go);
	if (go != 0)
	{
		dup2(save_fd[0], 0);
		dup2(save_fd[1], 1);
		close (save_fd[0]);
		close (save_fd[1]);
	}
	return (ret);
}

void	parent_act(int pid, t_vars *vars)
{
	int	status;

	init_sigs_not_interact(vars);
	gc_del(vars->list_gc, UNUSED, tab_parse_index, NULL);
	status = 0;
	waitpid(pid, &status, 0);
	get_ret_value(status, 1, vars);
}

void	ft_close(int t_fd[2])
{
	close (t_fd[0]);
	close (t_fd[1]);
}
