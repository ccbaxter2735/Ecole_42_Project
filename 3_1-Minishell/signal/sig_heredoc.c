/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:48:48 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/06 16:10:36 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	sig_handler_heredoc(int sig, siginfo_t *info, void *content)
{
	(void)content;
	(void)info;
	if (sig != SIGINT && sig != SIGQUIT)
		return ;
	if (sig == SIGINT)
	{
		write(0, "\0", 1);
		close(0);
	}
	else if (sig == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 0);
}

int	init_sigs_heredoc(t_vars *vars)
{
	struct sigaction	sa;

	if (sigemptyset(&(sa).sa_mask) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = sig_handler_heredoc;
	if (sigaction(SIGINT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	if (sigaction(SIGQUIT, &(sa), NULL) == -1)
		return (ft_error_parse(sig_err, vars->list_gc, 1), 1);
	return (0);
}

void	ft_restore_sig(t_vars *vars)
{
	init_sigs_interact(vars);
	init_sigs_interact(vars);
}
