/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:40:37 by pduhamel          #+#    #+#             */
/*   Updated: 2023/10/05 19:22:41 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK: gc_del la valeur ret
char	*get_env(char *str, t_vars *vars)
{
	char	*ret;
	int		len;
	int		i;
	int		info[3];

	info[0] = TEMP;
	info[1] = env_print;
	i = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	while ((vars->env_shell)[i] && ft_strncmp(str, (vars->env_shell)[i], len))
		i++;
	if ((vars->env_shell[i]) == NULL || (vars->env_shell)[i][len - 1] != '=')
		return (NULL);
	ret = ft_strdup_gc((vars->env_shell)[i] + ft_strlen(str), vars, info,
			ft_strlen((vars->env_shell)[i] + ft_strlen(str)) + 1);
	return (ret);
}

static int	ft_abs(int x)
{
	if (x >= 0)
		return (x * -1);
	return (x * -1);
}

int	ft_init_vars(int *len, int *i, int *x, int info[4])
{
	if (len)
		*len = 0;
	if (i)
		*i = -1;
	if (x)
		*x = 0;
	if (info)
	{
		if (!info[3])
			info[3] = 0;
		else
			info[3]++;
		info[0] = PERM;
		info[1] = env_id + info[3];
	}
	return (1);
}

// MARK: action : -1 supp 0 dump 1 set
char	**ft_env(char **env, t_vars *v, char *str, int action)
{
	char		**e_sh;
	int			len;
	int			i;
	int			x;
	static int	w[4];

	ft_init_vars(&len, &i, &x, w);
	while (env && env[len])
		len++;
	len += action;
	e_sh = gc_malloc((sizeof(char *) * (len + 1)), v, PERM, env_id + w[3]);
	while (++i + x < (len + ft_abs(action)))
	{
		if (action == -1 && !ft_strncmp(env[i + x], str, ft_strlen(str)) && i--)
			x = 1;
		else
			e_sh[i] = ft_strdup_gc(env[i + x], v, w, ft_strlen(env[i
						+ x]));
	}
	if (str && action == 1)
		e_sh[i++] = ft_strdup_gc(str, v, w, ft_strlen(str));
	e_sh[i] = NULL;
	if (action != 0 && v->env_shell)
		gc_del(v->list_gc, UNUSED, env_id + w[3] - 1, NULL);
	return (e_sh);
}

// MARK: Show env
int	print_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (printf("%s\n", env[i]) < 0)
			return (-42);
	}
	return (0);
}
