/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:10:31 by terussar          #+#    #+#             */
/*   Updated: 2023/07/18 18:01:18 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *file, int rd_wr, int check_in)
{
	int	fd;

	if (access(file, F_OK) == -1 && check_in == 0)
	{
		msg_error("zsh: no such file or directory: ", file);
		return (-1);
	}
	if (rd_wr == 0)
		fd = open(file, O_RDONLY, 0777);
	if (rd_wr == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		msg_error("zsh: permission denied: ", file);
		return (-1);
	}
	return (fd);
}

char	**find_path(char **env)
{
	char	**path;

	while (strncmp("PATH", *env, 4))
		env++;
	path = ft_split(*env + 5, ':');
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

char	*find_cmd(char *cmd, char **env)
{
	char	**path;
	int		i;
	char	*command;

	if (!cmd || !cmd[0])
		return (NULL);
	if (cmd[0] != '/' && cmd[0] != '.')
		path = find_path(env);
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
