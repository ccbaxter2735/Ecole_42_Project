/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:39:29 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/06 14:58:55 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	sig_handler_interactive(int sig, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	if (sig != SIGINT && !WIFEXITED(info->si_status))
		return ;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_ret_sig = sig;
}

int	init_sigs_interact(t_vars *vars)
{
	struct sigaction	sa;

	if (sigemptyset(&(sa).sa_mask) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	sa.sa_flags = 0;
	sa.sa_sigaction = sig_handler_interactive;
	if (sigaction(SIGINT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	return (0);
}

int	init_sigs_not_interact(t_vars *vars)
{
	struct sigaction	sa;

	if (sigemptyset(&(sa).sa_mask) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	sa.sa_flags = 0;
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGINT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	if (sigaction(SIGQUIT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	return (0);
}

void	ft_parent(int pid, t_vars *vars)
{
	int	status;

	init_sigs_not_interact(vars);
	waitpid(pid, &status, 0);
	get_ret_value(status, 1, vars);
	init_sigs_interact(vars);
}

int	restore_sig(t_vars *vars)
{
	struct sigaction	sa;

	if (sigemptyset(&(sa).sa_mask) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	sa.sa_flags = 0;
	sa.sa_handler = SIG_DFL;
	if (sigaction(SIGINT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	if (sigaction(SIGQUIT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	return (0);
}
