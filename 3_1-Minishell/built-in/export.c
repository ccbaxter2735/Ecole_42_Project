/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:46:16 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 20:58:58 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	find_in_env(char *tab_n, t_vars *vars, int *info)
{
	int		i;
	char	*str;

	i = 0;
	while (tab_n[i] && tab_n[i] != '=')
		i++;
	i++;
	str = ft_strdup_gc(tab_n, vars, info, i);
	if (get_env(str, vars) != NULL)
		vars->env_shell = ft_env_del(vars->env_shell, str, vars);
}

int	empty_str(char *str)
{
	int	i;

	i = 0;
	while (is_wsp(str[i]) || str[i] == '=')
		i++;
	if (i != ft_strlen(str))
		return (0);
	ft_putstr_fd("minishell: export: not a valid variable\n", 2);
	return (1);
}

void	init_var(int *i, int *j, int *n)
{
	*i = TEMP;
	*j = UNUSED;
	*n = 0;
}

void	exec_export_annexe(char *str, t_vars *vars, int *i)
{
	char	*tmp;

	tmp = erase_quote(str);
	if (exp_cdt(tmp) != 0 || empty_str(tmp) == 1)
		vars->ret_val = 1;
	else
	{
		find_in_env(tmp, vars, i);
		if (ft_strnstr(tmp, "=", ft_strlen(tmp)))
			vars->env_shell = ft_env_add(vars->env_shell, tmp, vars);
	}
	free(tmp);
}

int	exec_export(t_parse *pars, t_vars *vars, int go)
{
	char	**tab;
	int		i[6];
	int		n;

	init_var(&i[0], &i[1], &n);
	if (ft_strncmp(pars->cmd_arg, "export", 6) == 0)
	{
		if (!go)
			return (0);
		if (ft_strlen(pars->cmd_arg) > 6 && pars->cmd_arg[6] != ' ')
			return (msg_error("-minishell: command not found: ", pars->cmd_arg)
				, set_ret_val(vars, 127), 0);
		vars->ret_val = 0;
		tab = ft_split_parse(pars->cmd_arg, ' ', vars, i);
		if (len_tab(tab) < 2)
			return (0);
		while (tab[++n])
			exec_export_annexe(tab[n], vars, i);
		return (0);
	}
	return (1);
}
