/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:27:43 by terussar          #+#    #+#             */
/*   Updated: 2023/11/08 15:59:28 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : free heredoc
void	free_heredoc(t_here **list_heredoc, t_vars *vars)
{
	t_here	*tmp;
	t_here	*tmp_bis;

	(void)vars;
	tmp_bis = *list_heredoc;
	if (!tmp_bis)
		return ;
	while (tmp_bis->next != NULL)
	{
		tmp = tmp_bis;
		tmp_bis = tmp->next;
		free(tmp->line);
		free(tmp);
	}
	free(tmp_bis->line);
	free(tmp_bis);
	gc_del(vars->list_gc, UNUSED, p_split_index, NULL);
}

int	return_heredoc(t_parse *pars, t_here *list_heredoc, int t_fd[2], t_vars *v)
{
	int	fd;

	if (pars->next && (pars->next->nature == 1 || pars->next->nature == 0
			|| (pars->next->nature == 2 && pars->next->way == 1)))
	{
		if (pipe(t_fd) == -1)
			return (ft_perror("minishell: error:\npipe\n"), 1);
		print_list_heredoc(list_heredoc, t_fd[1]);
		close(t_fd[1]);
		fd = t_fd[0];
		if (fd == -1)
			return (1);
		if (dup2(fd, pars->way) == -1)
			return (1);
		close(fd);
	}
	else
	{
		free_heredoc(&list_heredoc, v);
		rl_clear_history();
		gc_clear(v->list_gc);
		exit (0);
	}
	return (0);
}

char	*ft_readline_heredoc(char *prompt, t_vars *vars)
{
	char	*str[2];
	char	*temp;
	int		info[2];

	info[0] = TEMP;
	info[1] = 0;
	ft_putstr_fd(prompt, STDIN_FILENO);
	temp = get_next_line(STDIN_FILENO);
	if (!temp)
		return (NULL);
	str[0] = ft_strdup_gc(temp, vars, info, ft_strlen(temp));
	str[1] = NULL;
	free(temp);
	return (*str);
}

char	*init_heredoc(t_here **list_heredoc, t_vars *v)
{
	char	*str;

	*list_heredoc = NULL;
	init_sigs_heredoc(v);
	str = ft_readline_heredoc("> ", v);
	error_heredoc(str);
	return (str);
}

int	heredoc(t_parse *pars, t_vars *v)
{
	char	*str;
	t_here	*list_heredoc;
	t_here	*new;
	char	*tmp;
	int		t_fd[2];

	str = init_heredoc(&list_heredoc, v);
	tmp = erase_quote(pars->redirec);
	while (str)
	{
		if (ft_strncmp(tmp, str, ft_strlen(tmp)) == 0
			&& (ft_strlen(tmp) + 1) == ft_strlen(str))
			break ;
		new = t_here_new(str);
		if (list_heredoc == NULL)
			list_heredoc = new;
		else
			get_last_elem_heredoc(list_heredoc)->next = new;
		str = ft_readline_heredoc("> ", v);
		if (error_heredoc(str) == 1)
			break ;
	}
	free(tmp);
	return_heredoc(pars, list_heredoc, t_fd, v);
	return (ft_restore_sig(v), free_heredoc(&list_heredoc, v), 0);
}
