/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:37:39 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 15:31:34 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : write char if option = 0 => echo and if option = 1 => echo -n
int	ft_echo(char *s, int option, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] == 34 || s[i] == 39)
			i = write_word_annexe2(s, i, vars);
		else
			i = write_word_annexe1(s, i, vars);
		if (i < 0)
			return (vars->ret_val = 1, msg_error("minishell:",
					" echo: write error: No space left on device"), -42);
		j = i;
		if (if_other_word(s, j) == 1 && s[i] == ' ')
			write(1, " ", 1);
	}
	if (option == 0)
	{
		if (write_err("\n", 0, vars) < 0)
			return (-42);
	}
	return (0);
}

int	check_n(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] && arg[i + 1] && arg[i] == '-' && arg[i + 1] == 'n')
	{
		i += 2;
		while (arg[i] && arg[i] == 'n')
			i++;
		if ((arg[i] && arg[i] == ' ') || !arg[i])
			return (1);
		return (0);
	}
	return (0);
}

int	exec_echo_annexe(t_parse *pars, t_vars *vars)
{
	int	i;
	int	j;
	int	option;

	i = 4;
	option = 0;
	while (pars->cmd_arg[i])
	{
		while (pars->cmd_arg[i] && pars->cmd_arg[i] == ' ')
			i++;
		j = i;
		if (pars->cmd_arg[i] && check_n(pars->cmd_arg + i) == 1)
		{
			option = 1;
			while (pars->cmd_arg[i] && pars->cmd_arg[i] != ' ')
				i++;
		}
		else
			return (ft_echo(pars->cmd_arg + j, option, vars));
	}
	if (option == 0)
		write_err("\n", 0, vars);
	vars->ret_val = 0;
	return (0);
}

static int	ft_echo_err(t_parse *pars, t_vars *vars)
{
	if (ft_strlen(pars->cmd_arg) > 4)
	{
		if (pars->cmd_arg[4] != ' ')
			return (msg_error("minishell: command not found: ", pars->cmd_arg),
				set_ret_val(vars, 127), 0);
	}
	return (1);
}

int	exec_echo(t_parse *pars, int go, t_vars *vars)
{
	if (ft_strncmp(pars->cmd_arg, "echo", 4) == 0)
	{
		if (!go || !ft_echo_err(pars, vars))
			return (0);
		vars->ret_val = 0;
		exec_echo_annexe(pars, vars);
		return (0);
	}
	return (1);
}
