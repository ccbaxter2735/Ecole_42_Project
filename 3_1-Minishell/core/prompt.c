/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:30:19 by terussar          #+#    #+#             */
/*   Updated: 2023/11/01 13:27:53 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : create, adapt and color prompt with pwd herepath
char	*ft_prompt(t_vars *vars)
{
	char	*ppt;
	char	*home;
	int		info[2];

	info[0] = TEMP;
	info[1] = prompt_index;
	home = get_env("PWD=", vars);
	if (!home)
		home = get_env("PWD=", vars);
	ppt = ft_strjoin_gc("\001\033[1;32m\002minishell:\001\033[1;34m\002",
			ft_strjoin_gc(home, "\001\033[0;37m\002$ ", vars, info),
			vars,
			info);
	return (ppt);
}
