/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:23:49 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/08 16:25:59 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Mark: detect quotes 0 -> quote 1 -> ' open 2 -> " open
int	quotes(int *quote, char c)
{
	if (c == 34)
	{
		if (*quote == 1)
		{
			*quote = 0;
			return (0);
		}
		else if (*quote == 0)
			*quote = 1;
	}
	else if (c == 39)
	{
		if (*quote == 2)
		{
			*quote = 0;
			return (0);
		}
		else if (*quote == 0)
			*quote = 2;
	}
	if (*quote)
		return (1);
	return (0);
}

char	*get_name(char *str, t_vars *vars, int *len)
{
	int		i[3];
	char	*name;
	char	*temp;

	i[0] = TEMP;
	i[1] = p_split_index;
	i[2] = 0;
	while (str[i[2]] && is_var(str[i[2]]))
		i[2]++;
	if (i[2] == 0)
		return (NULL);
	name = ft_strjoin_gc(ft_strdup_gc(str, vars, i, i[2]), "=", vars, i);
	*len = i[2];
	temp = name;
	name = get_env(name, vars);
	gc_del(vars->list_gc, UNUSED, UNUSED, temp);
	return (name);
}

static int	get_len(char *str, int x)
{
	int	i;

	i = 1;
	while (str[x + i] && is_var(str[x + i]))
		i++;
	if (str[x + i] == '?' && (!str[x + i + 1] || !is_var(str[x + i + 1])))
		i++;
	return (i);
}

// MARK: concatenate the start of string and replace
// the key by the value find in env
char	*super_join(char *str, int *x, t_vars *vars)
{
	int		i[3];
	char	*value;
	char	*st[4];

	i[1] = p_split_index;
	ft_init_vars(&i[0], NULL, &i[2], NULL);
	if (str[*x + 1] == '?')
		value = ft_expand(vars, i);
	else
		value = get_name(str + *x + 1, vars, &(i[2]));
	st[0] = ft_strdup_gc(str, vars, i, *x);
	if (value == NULL)
	{
		get_x(x, st[0]);
		if (*x + i[2] + 2 < ft_strlen(str))
			return (ft_strjoin_gc(st[0], ft_strdup_gc(str + i[2] + *x + 2,
						vars, i, ft_strlen(str + i[2] + *x + 2)), vars, i));
		return (st[0]);
	}
	st[3] = value;
	join_expand(x, st, vars, i);
	i[2] = get_len(str, *x);
	st[2] = ft_strjoin_gc(st[1], str + *x + i[2], vars, i);
	*x += ft_strlen(value) - 1;
	return (st[2]);
}

// MARK: put the value of the env var
int	ft_fill_str(char **p_tab, t_vars *v)
{
	int	i;
	int	x;
	int	quote;

	i = -1;
	while (p_tab[++i])
	{
		ft_init_vars(&x, NULL, &quote, NULL);
		while (p_tab[i] && p_tab[i][x]
			&& !ft_split_check(p_tab[i] + x, '|', v, &quote))
		{
			if (((p_tab[i][x] == '$' && quote == 1 && pick_token(p_tab[i],
						x) != 1) || (pick_token(p_tab[i], x) != 1
					&& p_tab[i][x] == '$' && quote != 2)
					|| (pick_token(p_tab[i], x) != 1 && p_tab[i][x] == '$'
						&& quote == 1)) && (ft_strlen(p_tab[i]) > x + 1)
						&& (is_var(p_tab[i][x]) || p_tab[i][x] == '$'))
				p_tab[i] = super_join(p_tab[i], &x, v);
			x++;
		}
		if (quote)
			return (ft_error_parse(quote_err, v->list_gc, 0), 1);
	}
	g_ret_sig = 0;
	return (0);
}
