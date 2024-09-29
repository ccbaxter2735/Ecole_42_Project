/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:50:38 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/07 05:36:38 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_empty(const char *str, char c, t_vars *vars)
{
	int	i;
	int	x;

	ft_init_vars(&i, NULL, &x, NULL);
	while (is_wsp(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	add_history(str);
	if (str[i] == '|' && str[i + 1] == '|')
		return (ft_error_parse(token_err, vars->list_gc, 0), 1);
	if (str[i] == '|')
		return (ft_error_parse(syntax_err, vars->list_gc, 0), 1);
	if (ft_end_split(str, vars))
		return (1);
	i = 0;
	if (ft_split_check(&(str[i]), c, vars, NULL))
		return (1);
	while (str[i] && is_wsp(str[i]))
		i++;
	while (str[x] && str[x] != c)
		x++;
	if (i == x || ft_check_token(str, vars))
		return (1);
	return (0);
}

int	ft_split_check(const char *str, char c, t_vars *vars, int *quote)
{
	if (quote)
		quotes(quote, *str);
	if (!quote && ((ft_strlen(str) >= 1 && ((*str == c && str[1] == c)
					|| (str[0] == '&' && str[1] == '&'))) || str[0] == ';'))
		return (ft_error_parse(token_err, vars->list_gc, 0), 1);
	return (0);
}

void	ft_blank(t_vars *vars, t_parse **cmd, int info[2])
{
	char	*tmp;

	tmp = (*cmd)->cmd_arg;
	(*cmd)->cmd_arg = ft_strjoin_gc((*cmd)->cmd_arg, " ", vars, info);
	gc_del(vars->list_gc, UNUSED, UNUSED, tmp);
}

int	ft_end_split(const char *str, t_vars *vars)
{
	int	len;
	int	i;
	int	pipe;
	int	quote;

	len = ft_strlen(str);
	ft_init_vars(&pipe, &i, NULL, NULL);
	while (str[++i] && (is_wsp(str[i]) || str[i] == '|'))
	{	
		if (str[i] == '|')
			pipe++;
	}
	if (i == len && pipe > 1)
		return (ft_error_parse(syntax_err, vars->list_gc, 0), 1);
	i = len;
	quote = 0;
	while (--i > 0 && is_wsp(str[i]) && str[i] != '|')
		quotes(&quote, str[i]);
	if (i >= 0 && str[i] == '|' && quote == 0)
	{
		if (i > 0 && str[i - 1] == '|')
			return (ft_error_parse(token_err, vars->list_gc, 0), 1);
		return (ft_error_parse(syntax_err, vars->list_gc, 0), 1);
	}
	return (0);
}

int	len_tab(char **str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
		return (i);
	while (str[i])
		i++;
	return (i);
}
