/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_annexe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:24:08 by terussar          #+#    #+#             */
/*   Updated: 2023/07/18 15:40:00 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_strerror(char *s)
{
	write(2, s, ft_strlen(s));
}

void	msg_error(char *s, char *str)
{
	ft_strerror(s);
	ft_strerror(str);
	ft_strerror("\n");
}

int	ft_perror(char *s)
{
	perror(s);
	return (1);
}

void	close_pipe(int nb1, int nb2)
{
	close(nb1);
	close(nb2);
}
