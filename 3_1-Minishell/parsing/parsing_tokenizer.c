/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokenizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:31:40 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/07 10:18:02 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_delim(char c, int token)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return (1);
	if (token == 1 && (c == 34 || c == 39))
		return (1);
	if (token == 3 && (c == '<' || c == '>'))
		return (1);
	else
		return (0);
}

int	pick_token(char *str, int x)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (x - i > 0 && !is_wsp(str[x - i]) && quotes(&quote, str[x - i]) >= 0)
		i++;
	while (x - i > 0 && is_wsp(str[x - i]))
		i++;
	while (x - i >= 0 && !is_wsp(str[x - i]) && quotes(&quote, str[x - i]) >= 0)
		i++;
	i--;
	if (i && !ft_strncmp((str + (x - i)), "<<", 2))
		return (1);
	else if (i && !ft_strncmp((str + (x - i)), "<", 1))
		return (2);
	else if (i && !ft_strncmp((str + (x - i)), ">>", 2))
		return (3);
	else if (i && !ft_strncmp((str + (x - i)), ">", 1))
		return (4);
	else if (i && !ft_strncmp((str + (x - i)), "|", 1) && !quote)
		return (5);
	else if (i)
		return (6);
	return (0);
}

int	ft_is_token(char *str, int *go_forward, t_vars *vars)
{
	int	i;
	int	x;
	int	quote;

	ft_init_vars(&i, NULL, &x, NULL);
	quote = 0;
	while (str[i] && is_wsp(str[i]))
		i++;
	while (str[i + x] && !is_wsp(str[i + x]) && quotes(&quote, str[x + i]) >= 0)
		x++;
	if (go_forward)
		*go_forward = 1 + (ft_is_token(str, NULL, vars) % 2);
	if (!ft_strncmp((str + i), ">>", 2))
		return (ft_check(str + 2 + i, vars, 1));
	else if (!ft_strncmp((str + i), ">", 1))
		return (ft_check(str + 1 + i, vars, 2));
	else if (!ft_strncmp((str + i), "<<", 2))
		return (ft_check(str + 2 + i, vars, 3));
	else if (!ft_strncmp((str), "<", 1))
		return (ft_check(str + 1, vars, 4));
	else if (!ft_strncmp((str), "|", 1) && !quote)
		return (5);
	else if (x)
		return (0);
	return (-1);
}

int	ft_tokener(char *str, int *i, t_vars *vars, t_parse **list_parse)
{
	int		x;
	int		token;
	int		info[5];
	char	*string;
	t_parse	*new;

	x = 0;
	info[0] = TEMP;
	info[1] = tab_parse_index;
	ft_init_vars(&(info[2]), NULL, &(info[4]), NULL);
	while (str[info[4] + *i] && is_delim(str[info[4] + *i], 3))
		info[4] += 1;
	while (str[info[4] + *i + x] && (quotes(&info[2], str[info[4] + *i + x])
			|| !is_wsp(str[info[4] + *i + x])))
		x++;
	token = ft_is_token(str, 0, vars);
	if (token <= 2)
		info[3] = 1;
	else
		info[3] = 0;
	string = ft_strdup_gc(str + info[4] + *i, vars, info, x);
	new = new_parse(1 + (token % 2), info[3], string, vars);
	ab_parse(list_parse, new);
	return (x - 1 + info[4]);
}

void	ft_cmd(char *str, int *i, t_vars *vars, t_parse **cmd)
{
	int		x;
	int		info[2];
	char	*string;
	char	*tmp;
	int		quote;

	x = 0;
	quote = 0;
	info[0] = TEMP;
	info[1] = tab_parse_index;
	while (str[*i + x] && (quotes(&quote, str[*i + x]) || (ft_is_token(str + *i
					+ x, NULL, vars) == 0)))
		x++;
	string = ft_strdup_gc(str + *i, vars, info, x);
	info[1] = tab_parse_index;
	if ((*cmd)->cmd_arg)
	{
		ft_blank(vars, cmd, info);
		tmp = (*cmd)->cmd_arg;
		(*cmd)->cmd_arg = ft_strjoin_gc((*cmd)->cmd_arg, string, vars, info);
		gc_del(vars->list_gc, UNUSED, UNUSED, tmp);
	}
	else
		(*cmd)->cmd_arg = ft_strdup_gc(string, vars, info, ft_strlen(string));
	*i += x - 1;
}
