/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:46:42 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 21:16:26 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_env(t_parse *pars, t_vars *vars, int go)
{
	if (ft_strncmp(pars->cmd_arg, "env", 3) == 0)
	{
		if (!go)
			return (0);
		if ((ft_strlen(pars->cmd_arg) > 3 && pars->cmd_arg[3] == ' ')
			|| ft_strlen(pars->cmd_arg) > 3)
		{
			if (pars->cmd_arg[3] == ' ')
				return (set_ret_val(vars, 2), ft_strerror
					("minishell: env does not take argument or option\n"), 0);
			return (msg_error("minishell: command not found: ", pars->cmd_arg),
				set_ret_val(vars, 127), 0);
		}
		if (print_env(vars->env_shell) < 0)
		{
			write_err("", 1, vars);
			return (-42);
		}
		vars->ret_val = 0;
		return (0);
	}
	return (1);
}
