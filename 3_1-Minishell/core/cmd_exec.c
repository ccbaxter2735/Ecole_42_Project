/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:18:13 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 15:49:12 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_err_cmd(char **tmp_split)
{
	msg_error("minishell: command not found: ", tmp_split[0]);
	free_array(tmp_split);
	exit(127);
}

char	**ft_cpytab(char **tab, t_vars *vars)
{
	char	**cpytab;
	int		i;

	cpytab = malloc(sizeof(char *) * (len_tab(tab) + 1));
	if (!cpytab)
		return (ft_error_parse(malloc_err, vars->list_gc, 1), NULL);
	i = -1;
	while (tab[++i])
		cpytab[i] = ft_strdup(tab[i]);
	cpytab[i] = 0;
	return (cpytab);
}

char	**free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

// MARK : find command's path in an environment and execute it if possible
int	cmd_exec(char *tmp, char **env, t_vars *vars)
{
	char	*cmd;
	char	**tmp_split;
	char	**env_bis;

	if (empty_quotes(tmp))
	{
		rl_clear_history();
		gc_clear(vars->list_gc);
		exit(127);
	}
	tmp = erase_quote(tmp);
	tmp_split = ft_split(tmp, ' ');
	free(tmp);
	cmd = find_cmd(tmp_split[0], env, vars, tmp_split);
	env_bis = ft_cpytab(env, vars);
	rl_clear_history();
	gc_clear(vars->list_gc);
	if (!cmd)
		cmd_failed(tmp_split, env_bis, 127);
	restore_sig(vars);
	if (execve(cmd, tmp_split, env_bis) == -1)
		ft_err_execve(tmp_split, env_bis, cmd);
	return (0);
}

void	get_ret_value(int status, int save, t_vars *vars)
{
	int	ret;

	ret = 0;
	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	else if (!WIFEXITED(status))
	{
		ret = WTERMSIG(status) + 128;
		if (ret == 131 && save)
			write(2, "Quit (core dumped)\n", 19);
		else if (ret == 130 && save)
			write(2, "\n", 2);
	}
	if (ret == 2)
		ret = 127;
	if (ret == 13)
		ret = 126;
	if (save)
		vars->ret_val = ret;
}
