/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:43:36 by pduhamel          #+#    #+#             */
/*   Updated: 2023/10/25 18:54:49 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_env_add(char **env, char *str, t_vars *vars)
{
	int		info[2];
	int		i;
	int		len;
	char	**env_shell;

	len = 0;
	vars->env_index++;
	info[0] = PERM;
	info[1] = env_id + vars->env_index;
	while (env && env[len])
		len++;
	env_shell = gc_malloc(sizeof(char *) * (len + 2), vars, info[0], info[1]);
	i = 0;
	while (i < len && env[i])
	{
		env_shell[i] = ft_strdup_gc(env[i], vars, info, ft_strlen(env[i]));
		i++;
	}
	env_shell[i] = ft_strdup_gc(str, vars, info, ft_strlen(str));
	env_shell[len + 1] = NULL;
	gc_del(vars->list_gc, UNUSED, env_id + vars->env_index - 1, NULL);
	return (env_shell);
}

char	**ft_env_del(char **env, char *str, t_vars *vars)
{
	int		info[2];
	int		i;
	int		x;
	int		len;
	char	**env_shell;

	len = 0;
	vars->env_index++;
	info[0] = PERM;
	info[1] = env_id + vars->env_index;
	while (env && env[len])
		len++;
	env_shell = gc_malloc(sizeof(char *) * (len), vars, info[0], info[1]);
	i = -1;
	x = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) != 0)
			env_shell[++x] = ft_strdup_gc(env[i], vars, info,
					ft_strlen(env[i]));
	}
	env_shell[len - 1] = NULL;
	gc_del(vars->list_gc, UNUSED, env_id + vars->env_index - 1, NULL);
	return (env_shell);
}
