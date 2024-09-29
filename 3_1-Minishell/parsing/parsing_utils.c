/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:30:21 by pduhamel          #+#    #+#             */
/*   Updated: 2023/11/06 18:40:39 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK: error func wich clear and quit
void	ft_error_parse(t_error error, t_list_gc *bordel, int n_exit)
{
	static char	*mess[] = {"minishell: malloc failed.\n",
		"minishell: quotes open\n", "minishell: invalid syntax.\n",
		"minishell: unauthorised token\n", "minishell: signal error\n"};

	ft_putstr_fd(mess[error], 2);
	if (error == syntax_err || error == token_err || error == quote_err)
		g_ret_sig = 2;
	if (n_exit)
	{
		gc_clear(bordel);
		exit(1);
	}
}

int	ft_check(char *str, t_vars *vars, int i)
{
	if (ft_is_token(str, NULL, vars) || (!str || !*str))
	{
		vars->ret_val = 2;
		return (-42);
	}
	return (i);
}

void	ab_parse(t_parse **list, t_parse *new)
{
	t_parse	*current;

	if (!(*list))
	{
		*list = new;
		(*list)->next = NULL;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}

t_parse	*new_parse(int nature, int way, char *str, t_vars *vars)
{
	t_parse	*new;

	new = gc_malloc(sizeof(t_parse), vars, TEMP, tab_parse_index);
	if (new == NULL)
		ft_error_parse(malloc_err, vars->list_gc, 1);
	new->nature = nature;
	new->way = way;
	new->pid = 0;
	new->cmd_arg = NULL;
	new->redirec = NULL;
	if (!nature)
		new->cmd_arg = str;
	else
		new->redirec = str;
	new->next = NULL;
	return (new);
}

int	is_wsp(char c)
{
	if (c == 32 || (c >= 8 && c <= 13))
		return (1);
	else
		return (0);
}
