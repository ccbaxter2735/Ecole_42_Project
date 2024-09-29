/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:13:03 by pduhamel          #+#    #+#             */
/*   Updated: 2023/10/05 17:05:36 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	print_list(t_vars *vars)
{
	t_parse	*curr;
	int		i;

	i = 0;
	if (!vars->tab_t_parse || !(*(vars->tab_t_parse)))
		return (printf("Nothing in list...\n"), 0);
	while (vars->tab_t_parse[i])
	{
		printf("|--beginning of list--|\n");
		printf("\n");
		curr = vars->tab_t_parse[i];
		while (curr)
		{
			printf("- - - - - - - - - - - -\n");
			printf("  Nature : %d | Way :%d\n  cmd_arg : %s\n  redirec :%s\n",
				curr->nature, curr->way, curr->cmd_arg, curr->redirec);
			printf("  next :%p\n", curr->next);
			printf("- - - - - - - - - - - -\n");
			curr = curr->next;
			printf("\n");
		}
		printf("|-----end of list-----|\n");
		i++;
	}
	return (i);
}

void	ft_init_list(t_vars *vars, int len, int info)
{
	int	i;

	i = -1;
	while (++i <= len)
		vars->tab_t_parse[i] = NULL;
	if (info)
		ab_parse(&(vars->tab_t_parse[len - 1]), new_parse(PIPE, 0, NULL, vars));
}

char	*str_token(char *str, t_vars *vars, char *token, int *i)
{
	int		info[2];
	char	*sttr[2];

	info[0] = TEMP;
	info[1] = p_split_index;
	sttr[0] = ft_strdup_gc(str, vars, info, *i);
	sttr[1] = ft_strjoin_gc(sttr[0], token, vars, info);
	if (*(str + *i + 2))
		str = ft_strjoin_gc(sttr[1], str + *i + 2, vars, info);
	else
		str = sttr[1];
	*i += 1;
	return (str);
}

void	join_expand(int *x, char *st[4], t_vars *vars, int info[2])
{
	if (*x)
		st[1] = ft_strjoin_gc(st[0], st[3], vars, info);
	else
		st[1] = st[3];
}
