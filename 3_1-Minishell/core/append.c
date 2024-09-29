/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:33:34 by terussar          #+#    #+#             */
/*   Updated: 2023/10/05 21:59:18 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK :  >> append or create exit into another fd
t_parse	*append(t_parse *pars)
{
	int		fd;
	t_parse	*test;

	test = pars;
	if (test != NULL)
	{
		if (test->nature == 2 && test->way == 1)
		{
			fd = open_file(test->redirec, 1, test->nature);
			if (fd == -1)
				exit (1);
			if (dup2(fd, 1) == -1)
				exit (1);
			close(fd);
		}
	}
	return (test);
}
