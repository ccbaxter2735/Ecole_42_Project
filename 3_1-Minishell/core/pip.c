/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:29:55 by terussar          #+#    #+#             */
/*   Updated: 2023/11/07 00:41:00 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	annexe_pipe(int last_fd, int t_fd[2], t_parse *pars, t_vars *vars)
{
	if (!last_fd)
		dup2(t_fd[1], 1);
	ft_close(t_fd);
	exec_redir(pars, vars);
	while (pars != NULL && pars->nature != 0)
		pars = pars->next;
	if (ft_empty_pars(pars, vars))
		exit(127);
	exec_fct(pars, vars);
}

// MARK : execute pipe
int	exec_pipe(t_parse *pars, t_vars *vars, int last_fd)
{
	int		pid1;
	int		t_fd[2];

	if (pipe(t_fd) == -1)
		return (ft_perror("minishell: error:\npipe\n"));
	pid1 = fork();
	add_pid(pid1, vars->pid_pipe);
	if (pid1 == -1)
		return (ft_perror("minishell: error:\nfork\n"));
	if (pid1 == 0)
	{
		annexe_pipe(last_fd, t_fd, pars, vars);
		gc_clear(vars->list_gc);
		rl_clear_history();
		exit(0);
	}
	init_sigs_not_interact(vars);
	dup2(t_fd[0], 0);
	ft_close(t_fd);
	return (t_fd[0]);
}

int	exec_multipipe(t_vars *vars, int len)
{
	t_parse	**tab;
	int		i;
	int		last_fd;

	last_fd = -1;
	i = 0;
	vars->pid_pipe = gc_malloc(sizeof(int) * (ft_tab_len(vars->tab_t_parse)
				+ 1), vars, TEMP, UNUSED);
	ft_fill_pid(vars->pid_pipe, ft_tab_len(vars->tab_t_parse));
	init_sigs_not_interact(vars);
	tab = vars->tab_t_parse;
	while (i < (len - 1))
	{
		exec_pipe(tab[i], vars, 0);
		i++;
	}
	exec_pipe(tab[i], vars, 1);
	wait_pid(vars);
	gc_clear(vars->list_gc);
	exit(vars->ret_val);
}
