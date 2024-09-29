/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:18:50 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 21:29:22 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : check if cmd_arg is a built-in function
int	exec_built_in(t_parse *pars, t_vars *vars, int go)
{
	if (exec_cd(pars, vars, go) == 0)
		return (0);
	if (exec_echo(pars, go, vars) == 0)
		return (0);
	if (exec_env(pars, vars, go) == 0)
		return (0);
	if (exec_exit(pars, vars, go) == 0)
		return (0);
	if (exec_export(pars, vars, go) == 0)
		return (0);
	if (exec_pwd(pars, vars, go) == 0)
		return (0);
	if (exec_unset(pars, vars, go) == 0)
		return (0);
	return (1);
}

// MARK : execute cmd_arg, check if it's built-in else exec fct env linux
void	exec_fct(t_parse *pars, t_vars *vars)
{
	if (exec_built_in(pars, vars, 1) == 1 && pars)
		pars->pid = cmd_exec(pars->cmd_arg, vars->env_shell, vars);
}
