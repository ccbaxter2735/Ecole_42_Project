/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:17:41 by terussar          #+#    #+#             */
/*   Updated: 2023/11/06 21:28:11 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_ret_sig;

int	main(int ac, char **av, char **env)
{
	t_vars	vars;
	int		ret_value;

	(void)av;
	(void)ac;
	init_parse(env, &vars);
	init_sigs_interact(&vars);
	loop_prompt(&vars);
	gc_clear(vars.list_gc);
	rl_clear_history();
	printf("exit\n");
	get_ret_val(&ret_value, &vars);
	return (ret_value);
}
