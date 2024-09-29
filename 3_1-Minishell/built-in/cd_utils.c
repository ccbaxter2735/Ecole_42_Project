/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:26 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 21:03:13 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	return_path(char *path, t_vars *vars)
{
	int	info[2];
	int	i;

	info[0] = TEMP;
	info[1] = UNUSED;
	i = 0;
	if (len_tab(ft_split_gc(path, ' ', vars, info)) > 1)
		ft_strerror("minishell: cd: too many arguments\n");
	else
		msg_error("minishell: cd: no file or directory: ", path);
	vars->ret_val = 1;
}

int	ft_cd_err(t_parse *pars, t_vars *vars)
{
	if (ft_strlen(pars->cmd_arg) > 2)
	{
		if (pars->cmd_arg[2] == ' ' && is_options(pars->cmd_arg + 2))
			return (set_ret_val(vars, 2), ft_strerror
				("minishell: cd does not take option\n"), 0);
		if (pars->cmd_arg[2] != ' ')
			return (msg_error("minishell: command not found: ", pars->cmd_arg),
				set_ret_val(vars, 127), 0);
	}
	return (1);
}
