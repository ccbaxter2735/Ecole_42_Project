/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:04:03 by terussar          #+#    #+#             */
/*   Updated: 2023/07/18 17:59:49 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>
# include <fcntl.h>

int		open_file(char *file, int rd_wr, int check_in);
int		ft_perror(char *s);
char	**find_path(char **env);
char	*find_cmd(char *cmd, char **env);
void	free_option(char **option);
void	ft_strerror(char *s);
void	msg_error(char *s, char *str);
void	free_array(char **option);
void	close_pipe(int nb1, int nb2);

#endif