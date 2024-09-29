/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:10 by terussar          #+#    #+#             */
/*   Updated: 2023/11/07 09:51:40 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_pid(int pid, int *pid_pipe)
{
	int	i;

	i = 0;
	if (!pid_pipe)
		return ;
	while (pid_pipe[i] != 0 && pid_pipe[i] != -42)
		i++;
	if (!pid_pipe[i])
		pid_pipe[i] = pid;
}

void	ft_fill_pid(int *pid_pipe, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pid_pipe[i] = 0;
		i++;
	}
	pid_pipe[i] = -42;
}

void	wait_pid(t_vars *vars)
{
	int	c_stopped;
	int	i;
	int	status;
	int	len;

	c_stopped = 0;
	len = ft_tab_len(vars->tab_t_parse);
	i = 0;
	while (c_stopped < len)
	{
		if (waitpid(vars->pid_pipe[i], &status, WNOHANG) > 0)
		{
			if (i == (len - 1))
				get_ret_value(status, 1, vars);
			else
				get_ret_value(status, 0, vars);
			c_stopped++;
		}
		if (i == len - 1)
			i = 0;
		else
			i++;
	}
}

void	cmd_failed(char **tmp_split, char **env_bis, int retval)
{
	if (retval == 127)
		msg_error("minishell: command not found: ", tmp_split[0]);
	if (retval == 126)
		msg_error("minishell: is a directory: ", tmp_split[0]);
	free_split(tmp_split);
	free_split(env_bis);
	exit(retval);
}
