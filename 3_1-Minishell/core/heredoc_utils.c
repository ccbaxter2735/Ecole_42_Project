/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:42:08 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 15:52:51 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_here	*t_here_new(char *str)
{
	t_here	*here;

	here = malloc(sizeof(t_here));
	if (here != NULL)
	{
		here->line = ft_strdup(str);
		here->next = NULL;
	}
	return (here);
}

t_here	*get_last_elem_heredoc(t_here *list_heredoc)
{
	t_here	*elem;

	elem = list_heredoc;
	while (elem != NULL)
	{
		if (elem->next == NULL)
			return (elem);
		elem = elem->next;
	}
	return (elem);
}

// MARK : print list heredoc
void	print_list_heredoc(t_here *list_heredoc, int fd)
{
	t_here	*elem;

	elem = list_heredoc;
	while (elem != NULL)
	{
		ft_putstr_fd(elem->line, fd);
		elem = elem->next;
	}
}

int	error_heredoc(char *str)
{
	if (!str)
	{
		ft_putstr_fd("\nminishell: warning: here-document stopped\n", 2);
		return (1);
	}
	return (0);
}
