/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:31:31 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 22:28:37 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : redirect entry or exit into another fd
int	redirect(t_parse *pars)
{
	int		fd;

	if (pars != NULL)
	{
		if (pars->nature == 1)
		{
			fd = open_file(pars->redirec, pars->way, pars->nature);
			if (fd == -1)
				return (1);
			if (dup2(fd, pars->way) == -1)
				return (1);
			close(fd);
		}
	}
	return (0);
}
