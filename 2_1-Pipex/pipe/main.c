/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:03:41 by terussar          #+#    #+#             */
/*   Updated: 2023/07/18 18:09:13 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	child1(char **av, int *pfd, char **env)
{
	int		fd;
	char	*cmd;
	char	**option1;

	fd = open_file(av[1], 0, 0);
	if (fd == -1)
	{
		close_pipe(pfd[0], pfd[1]);
		exit(1);
	}
	dup2(pfd[1], 1);
	close_pipe(pfd[0], pfd[1]);
	dup2(fd, 0);
	close(fd);
	option1 = ft_split(av[2], ' ');
	cmd = find_cmd(option1[0], env);
	if (!cmd)
	{
		free_array(option1);
		msg_error("zsh: command not found: ", av[2]);
		exit(1);
	}
	execve(cmd, option1, env);
	exit(1);
}

void	child2(char **av, int *pfd, char **env)
{
	int		fd;
	char	*cmd;
	char	**option2;

	fd = open_file(av[4], 1, 1);
	if (fd == -1)
	{
		close_pipe(pfd[0], pfd[1]);
		exit(1);
	}
	dup2(pfd[0], 0);
	close_pipe(pfd[0], pfd[1]);
	dup2(fd, 1);
	close(fd);
	option2 = ft_split(av[3], ' ');
	cmd = find_cmd(option2[0], env);
	if (!cmd)
	{
		free_array(option2);
		msg_error("zsh: command not found: ", av[3]);
		exit(1);
	}
	execve(cmd, option2, env);
	exit(1);
}

int	parsing(int ac)
{
	if (ac != 5)
	{
		ft_strerror("error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int		pid1;
	int		pid2;
	int		pfd[2];

	if (parsing(ac) != 0)
		return (1);
	if (pipe(pfd) == -1)
		return (ft_perror("pipe"));
	pid1 = fork();
	if (pid1 == -1)
		return (ft_perror("fork"));
	if (pid1 == 0)
		child1(av, pfd, env);
	pid2 = fork();
	if (pid2 == -1)
		return (ft_perror("fork"));
	if (pid2 == 0)
		child2(av, pfd, env);
	close(pfd[0]);
	close(pfd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
