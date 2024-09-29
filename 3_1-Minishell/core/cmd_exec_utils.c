/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:18:20 by terussar          #+#    #+#             */
/*   Updated: 2023/11/07 10:13:26 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : find PATH in env (where linux's funct are)
char	**find_path(char **env, t_vars *vars, char *cmd, char **tmp_split)
{
	char	**path;

	path = NULL;
	while (env && *env && strncmp("PATH", *env, 4))
		env++;
	if (env && *env)
		path = ft_split(*env + 5, ':');
	if (!path)
	{
		msg_error("minishell: command not found: ", cmd);
		free_array(tmp_split);
		rl_clear_history();
		gc_clear(vars->list_gc);
		exit(127);
	}
	return (path);
}

char	*test(char *cmd, char *path_i)
{
	char	*tmp;
	char	*command;

	tmp = ft_strjoin(path_i, "/");
	command = ft_strjoin(tmp, cmd);
	free(tmp);
	return (command);
}

char	*find_cmd(char *cmd, char **env, t_vars *vars, char **tmp_split)
{
	char	**path;
	int		i;
	char	*command;

	if (!cmd || !cmd[0])
		return (NULL);
	if (cmd[0] != '/' && cmd[0] != '.')
		path = find_path(env, vars, cmd, tmp_split);
	else
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	i = -1;
	while (path[++i])
	{
		command = test(cmd, path[i]);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
	}
	free_array(path);
	return (NULL);
}

void	ft_err_execve(char **tmp_split, char **env_bis, char *cmd)
{
	if (errno == 13)
		cmd_failed(tmp_split, env_bis, 126);
	if (errno == 2)
		cmd_failed(tmp_split, env_bis, 127);
	free(cmd);
}
