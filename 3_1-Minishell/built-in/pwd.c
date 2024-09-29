/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:29:32 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 15:33:35 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_options(char *str)
{
	int	quote;
	int	i;

	i = -1;
	quote = 0;
	while (str[++i])
	{
		quotes(&quote, str[i]);
		if (str[i] == '-' && !quote && !is_wsp(str[i + 1])
			&& i != ft_strlen(str) - 1)
			return (1);
	}
	return (0);
}

int	exec_pwd(t_parse *pars, t_vars *vars, int go)
{
	if (ft_strncmp(pars->cmd_arg, "pwd", 3) == 0)
	{
		if (!go)
			return (0);
		if ((ft_strlen(pars->cmd_arg) > 3 && pars->cmd_arg[3] == ' ')
			|| ft_strlen(pars->cmd_arg) > 3)
		{
			if (pars->cmd_arg[3] == ' ')
				return (set_ret_val(vars, 2),
					ft_strerror(
						"minishell: pwd does not take argument or option\n"), 0);
			return (msg_error("minishell: command not found: ", pars->cmd_arg),
				set_ret_val(vars, 127), 0);
		}
		if (printf("%s\n", get_env("PWD=", vars)) < 0)
		{
			write_err("", 2, vars);
			return (-42);
		}
		vars->ret_val = 0;
		return (0);
	}
	return (1);
}
