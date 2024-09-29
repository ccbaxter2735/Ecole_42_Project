/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:46:11 by terussar          #+#    #+#             */
/*   Updated: 2023/11/07 06:41:06 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_exit(int n, t_vars *vars)
{
	static char	*mess[] = {"%s too many arguments\n",
		"%s numeric argument required\n"};

	printf(mess[n], "minishell: exit:");
	if (n == 1)
	{
		close (vars->fd_dup[0]);
		close (vars->fd_dup[1]);
		gc_clear(vars->list_gc);
		rl_clear_history();
		exit(2);
	}
	else if (n == 0)
		vars->ret_val = 1;
}

static long long	ft_atoi_exit(const char *nptr, t_vars *vars)
{
	int					i;
	unsigned long long	signe;
	unsigned long long	tt;

	i = 0;
	signe = 1;
	tt = 0;
	while (nptr[i] == ' ' || (nptr[i] > 7 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		tt = tt * 10 + (nptr[i] - '0');
		if (tt > 9223372036854775807)
			ft_exit(1, vars);
		i++;
	}
	return (signe * tt);
}

static int	get_nb(char *st, t_vars *vars)
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	while (st[i])
	{
		if ((st[i] < 48 || st[i] > 57) && st[i] != '-')
			ft_exit(1, vars);
		i++;
	}
	nb = ft_atoi_exit(st, vars);
	if (nb == -2147483648)
		return (0);
	if (nb < 0)
		return ((nb % 256) + 256);
	return (nb % 255);
}

static	int	ft_exit_err(t_parse *pars, t_vars *vars)
{
	if (ft_strlen(pars->cmd_arg) > 4)
	{
		if (pars->cmd_arg[4] == ' ' && is_options(pars->cmd_arg + 4))
			return (set_ret_val(vars, 2), ft_strerror
				("minishell: exit does not take option\n"), 0);
		if (pars->cmd_arg[4] != ' ')
			return (msg_error("minishell: command not found: ", pars->cmd_arg),
				set_ret_val(vars, 127), 0);
	}
	return (1);
}

int	exec_exit(t_parse *pars, t_vars *vars, int go)
{
	char	**tab;
	int		info[2];
	int		ret_val;

	if (ft_strncmp(pars->cmd_arg, "exit", 4) == 0)
	{
		if (!go || !ft_exit_err(pars, vars))
			return (0);
		info[0] = TEMP;
		info[1] = UNUSED;
		printf("exit\n");
		tab = ft_split_wsp(pars->cmd_arg, info, vars);
		if (len_tab(tab) > 1)
			ret_val = get_nb(tab[1], vars);
		else
			ret_val = vars->ret_val;
		close (vars->fd_dup[0]);
		close (vars->fd_dup[1]);
		if (len_split(tab) > 2)
			return (ft_exit(0, vars), 1);
		gc_clear(vars->list_gc);
		rl_clear_history();
		exit(ret_val);
	}
	return (1);
}
