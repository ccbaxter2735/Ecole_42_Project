/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:31:56 by terussar          #+#    #+#             */
/*   Updated: 2023/11/07 06:03:55 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// MARK : test file's existence and open it, create it or append it
int	open_file(char *file, int rd_wr, int nature)
{
	int	fd;

	if (access(file, F_OK) == -1 && rd_wr == 0)
	{
		msg_error("minishell: no such file or directory: ", file);
		return (-1);
	}
	if (rd_wr == 0)
		fd = open(file, O_RDONLY, 0777);
	if (rd_wr == 1 && nature == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (rd_wr == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		msg_error("minishell: permission denied: ", file);
		return (-1);
	}
	return (fd);
}
