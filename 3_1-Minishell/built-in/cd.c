/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:29:35 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 18:17:12 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : look for the line containing pwd and oldpwd inside env
char	*find_line_env(char **env, char *line_to_search)
{
	char	*path;

	while (strncmp(line_to_search, *env, ft_strlen(line_to_search)))
		env++;
	path = ft_strdup(*env);
	return (path);
}

// MARK : erase pwd and oldpwd inside env
//and recreates it according to cd function
void	change_pwd_env(t_vars *vars, char *pwd, char *newpwd)
{
	char	*path_pwd;
	char	*path_oldpwd;

	path_pwd = ft_strjoin("PWD=", newpwd);
	path_oldpwd = ft_strjoin("OLDPWD=", pwd + 4);
	vars->env_shell = ft_env_del(vars->env_shell, "PWD=", vars);
	vars->env_shell = ft_env_del(vars->env_shell, "OLDPWD=", vars);
	vars->env_shell = ft_env_add(vars->env_shell, path_pwd, vars);
	vars->env_shell = ft_env_add(vars->env_shell, path_oldpwd, vars);
	free(path_oldpwd);
	free(path_pwd);
}

char	*exec_cd_annexe(char *arg, t_vars *vars)
{
	char	*path;
	int		info[2];

	info[0] = TEMP;
	info[1] = UNUSED;
	if (ft_strncmp(arg, "~", 1) == 0 || ft_strncmp(arg, "\0", 1) == 0)
		path = ft_strjoin_gc(get_env("HOME=", vars), (arg + 1), vars, info);
	else if (ft_strncmp(arg, "-", 1) == 0)
	{
		path = ft_strjoin_gc(get_env("OLDPWD=", vars), (arg + 1), vars, info);
		printf("%s\n", path);
	}
	else
		path = arg;
	return (path);
}

char	*ft_arg(t_parse *pars)
{
	char	*arg;

	if (ft_strlen(pars->cmd_arg) < 3)
		arg = "\0";
	else
	{
		pars->cmd_arg += 3;
		while (*pars->cmd_arg == ' ')
			pars->cmd_arg++;
		arg = pars->cmd_arg;
		while (arg[0] == ' ')
			arg = arg + 1;
	}
	return (arg);
}

// MARK : exec cd linux fct with path, ~, and - argument
int	exec_cd(t_parse *pars, t_vars *vars, int go)
{
	char	*arg;
	char	*path;
	char	*quote;
	char	*pwd;
	char	buf[100];

	if (ft_strncmp(pars->cmd_arg, "cd", 2) == 0)
	{
		if (!go || !ft_cd_err(pars, vars))
			return (0);
		pwd = find_line_env(vars->env_shell, "PWD=");
		arg = ft_arg(pars);
		path = exec_cd_annexe(arg, vars);
		quote = erase_quote(path);
		if (chdir(quote) == -1 || !getcwd(buf, 100))
		{
			return_path(path, vars);
			return (free(pwd), free(quote), 0);
		}
		change_pwd_env(vars, pwd, getcwd(buf, 100));
		free(pwd);
		vars->ret_val = 0;
		return (free(quote), 0);
	}
	return (1);
}
