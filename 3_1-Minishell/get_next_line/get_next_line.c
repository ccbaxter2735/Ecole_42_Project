/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:51:34 by terussar          #+#    #+#             */
/*   Updated: 2023/10/05 14:22:18 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*join_free(char *s, char *buf)
{
	char	*tmp;

	if (!s)
		s = ft_calloc(1, sizeof(char));
	tmp = ft_strjoin(s, buf);
	free(s);
	return (tmp);
}

char	*loop(int fd, char *s)
{
	char	*buf;
	int		size;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	size = 1;
	while (size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[size] = '\0';
		s = join_free(s, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (s);
}

char	*get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*keep_line(char *s)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen(s) - i + 1), sizeof(char));
	if (!tmp)
	{
		free(s);
		return (NULL);
	}
	i++;
	j = 0;
	while (s[i])
		tmp[j++] = s[i++];
	free(s);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*s;
	char	*line;

	s = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	s = loop(fd, s);
	if (!s)
		return (NULL);
	line = get_line(s);
	if (s)
		free(s);
	return (line);
}
