/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:00:55 by terussar          #+#    #+#             */
/*   Updated: 2023/01/04 16:52:24 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_free(char *s, char	*buf)
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
	static char	*s[1024];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	s[fd] = loop(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = get_line(s[fd]);
	if (!s[fd])
	{
		free(s[fd]);
		return (NULL);
	}
	s[fd] = keep_line(s[fd]);
	return (line);
}

// int	main()
// {
// 	int			fd1;
// 	int			fd2;
// 	char 	*str1;
// 	char 	*str2;
// 	int				i;

// 	fd1 = open("homer_dans_l_espace.txt", O_RDONLY);
// 	fd2 = open("homer_et_potchie.txt", O_RDONLY);
// 	i = 0;
// 	while(i < 25)
// 	{
// 		printf("%s", str1 = get_next_line(fd1));
// 		printf("\n");
// 		free(str1);
// 		printf("%s", str2 = get_next_line(fd2));
// 		printf("\n");
// 		free(str2);
// 		i++;
// 	}
// }
