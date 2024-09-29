/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:53:28 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/08 18:18:26 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : init gc and get the env
char	**init_parse(char **env, t_vars *vars)
{
	vars->list_gc = NULL;
	if (env && *env && len_tab(env) > 2)
		vars->env_shell = ft_env(env, vars, NULL, 0);
	else
	{
		vars->env_shell = NULL;
		get_vars_env(vars);
	}
	vars->ret_val = 0;
	vars->prev_state = regular_state;
	vars->state = regular_state;
	vars->env_index = 0;
	g_ret_sig = 0;
	return (NULL);
}

void	print_parsing(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("parsing : |%s|\n", tab[i]);
		i++;
	}
}

int	len_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !tab[0])
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	parsing(char *tmp, t_vars *v)
{
	char	**p_tab;
	int		info[6];
	int		len;

	info[0] = TEMP;
	info[1] = p_split_index;
	v->tab_t_parse = NULL;
	if (ft_empty(tmp, '|', v))
		return (free(tmp), 1);
	p_tab = ft_split_parse(tmp, '|', v, info);
	info[5] = ft_end_split(tmp, v);
	if (clear_tmp(tmp))
		return (1);
	if (info[5])
		return (ft_error_parse(syntax_err, v->list_gc, 0), 1);
	len = len_split(p_tab) + info[5];
	v->tab_t_parse = gc_malloc(sizeof(t_parse *) * (len + 1),
			v, TEMP, tab_parse_index);
	if (!v->tab_t_parse || !p_tab)
		return (ft_error_parse(malloc_err, v->list_gc, 0), 1);
	ft_init_list(v, len, info[5]);
	if (ft_fill_str(p_tab, v) || ft_build_list(p_tab, v) || !(*v->tab_t_parse))
		return (gc_del(v->list_gc, UNUSED, p_split_index, NULL), 1);
	gc_del(v->list_gc, UNUSED, p_split_index, NULL);
	return (0);
}

void	get_vars_env(t_vars *vars)
{
	int		info[2];
	char	buf[100];
	char	*buff;
	char	*tmp;
	int		i;

	info[0] = TEMP;
	info[1] = UNUSED;
	getcwd(buf, 100);
	buff = ft_strdup_gc(buf, vars, info, ft_strlen(buf));
	info[0] = PERM;
	tmp = ft_strjoin_gc("PWD=", buff, vars, info);
	vars->env_shell = ft_env_add(vars->env_shell, tmp, vars);
	vars->env_shell = ft_env_add(vars->env_shell, ft_strjoin_gc("OLDPWD=", buff,
				vars, info), vars);
	i = 0;
	info[0] = PERM;
	tmp = NULL;
	while (buff[i] && ft_strncmp(buff + i, "homes/", 6) != 0)
		i++;
	i += 6;
	while (buff[i] != '/')
		i++;
	tmp = ft_strjoin_gc("HOME=", ft_strdup_gc(buff, vars, info, i), vars, info);
	vars->env_shell = ft_env_add(vars->env_shell, buff, vars);
}
