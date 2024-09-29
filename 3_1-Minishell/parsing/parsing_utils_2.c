/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:43:43 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/07 03:52:54 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_expand(t_vars *vars, int i[3])
{
	char	*str;
	int		ret_value;

	if (g_ret_sig)
	{
		ret_value = g_ret_sig + 128;
		str = ft_itoa_gc(ret_value, vars, i);
	}
	else
		str = ft_itoa_gc(vars->ret_val, vars, i);
	return (str);
}

int	is_var(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9') || c == '_')
		return (1);
	else
		return (0);
}

void	get_ret_val(int *ret_value, t_vars *vars)
{
	if (g_ret_sig)
		*ret_value = g_ret_sig + 128;
	else
		*ret_value = vars->ret_val;
}

int	clear_tmp(char *tmp)
{
	add_history(tmp);
	free(tmp);
	return (0);
}

int	empty_quotes(char *str)
{
	int	i;
	int	something;

	i = -1;
	something = 0;
	while (str[++i])
	{
		if (!is_wsp(str[i]) && str[i] != 34 && str[i] != 39)
			something = 1;
	}
	if (!something)
	{
		printf("lol\n");
		ft_putstr_fd("minishell: command not found: \n", 2);
		return (1);
	}
	return (0);
}
