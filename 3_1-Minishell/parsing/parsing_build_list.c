/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_build_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:37:49 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/07 05:29:57 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_parse	*ft_one_list(char *str, t_vars *vars)
{
	t_parse	*list_parse;
	t_parse	*cmd;
	int		i;
	int		len;

	i = 0;
	cmd = new_parse(CMD, 0, NULL, vars);
	list_parse = NULL;
	while (str[i])
	{
		while (str[i] && is_wsp(str[i]))
			i++;
		if (ft_is_token(str + i, NULL, vars) == -42)
			return (NULL);
		if (ft_is_token(str + i, NULL, vars) > 0 && ft_is_token(str + i, &len,
				vars) < 5)
			i += ft_tokener(str + i, &len, vars, &list_parse) + len;
		else if (ft_is_token(str + i, NULL, vars) == 0)
			ft_clear_cmd(str, &i, vars, &cmd);
		if (i < ft_strlen(str))
			i++;
	}
	if (cmd->cmd_arg)
		ab_parse(&list_parse, cmd);
	return (list_parse);
}

int	ft_build_list(char **p_tab, t_vars *vars)
{
	int	i;

	i = 0;
	if (p_tab[i] && *(p_tab[i]) == 0)
		return (0);
	while (p_tab[i])
	{
		if (*p_tab[i] == '\0')
			return (ft_error_parse(syntax_err, vars->list_gc, 0), 1);
		vars->tab_t_parse[i] = ft_one_list(p_tab[i], vars);
		if (!vars->tab_t_parse[i])
			return (ft_error_parse(syntax_err, vars->list_gc, 0), 1);
		i++;
	}
	return (0);
}
// printf("len %d\n", len_split(p_tab));
