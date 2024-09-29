/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:10:03 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/08 15:34:34 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_empty_pars(t_parse *pars, t_vars *vars)
{
	if (!pars || !pars->cmd_arg)
		return (0);
	if (empty_quotes(pars->cmd_arg))
	{
		rl_clear_history();
		gc_clear(vars->list_gc);
		return (1);
	}
	return (0);
}

int	ft_check_token(const char *str, t_vars *vars)
{
	int		quote;
	int		i;
	char	c;

	quote = 0;
	i = -1;
	c = '|';
	while (str[++i])
	{
		quotes(&quote, str[i]);
		if (!quote && ((ft_strlen(str) >= 1 && ((str[i] == '|' && str[i
								+ 1] == '|') || (str[i] == '&' && str[i
								+ 1] == '&'))) || str[i] == ';'))
			return (ft_error_parse(token_err, vars->list_gc, 0), 1);
	}
	return (0);
}

void	ft_clear_cmd(char *str, int *i, t_vars *vars, t_parse **cmd)
{
	int	x;

	x = 0;
	while ((str[*i + x] == 39 && str[*i + x + 1] == 39) || (str[*i + x] == 34
			&& str[*i + x + 1] == 34))
		x += 2;
	*i += x;
	ft_cmd(str, i, vars, cmd);
}

void	get_x(int *x, char *str)
{
	if (str && ft_strlen(str) > 0)
		*x = ft_strlen(str) - 1;
	else
		*x = 0;
}
