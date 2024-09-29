/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:57:42 by pduhamel          #+#    #+#             */
/*   Updated: 2022/12/20 18:16:29 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//---------------------------------

char	*ft_read(int fd, char *temp)
{
	char	*buf;
	int		r;

	if (is_n(temp) >= 0)
		return (temp);
	while (is_n(temp) < 0)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buf)
			return (NULL);
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			free(buf);
			if (r == 0 && temp != NULL)
				return (temp);
			return (NULL);
		}
		temp = ft_strjoin(temp, buf);
		if (!temp)
			return (NULL);
		free(buf);
	}
	return (temp);
}

char	*get_line(char *temp)
{
	char	*str;
	int		i;
	int		l;

	l = is_n(temp);
	if (l >= 0 && l < (int)ft_strlen(temp) - 1)
		str = ft_calloc(l + 2, 1);
	else
		str = ft_calloc(ft_strlen(temp) + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	if (l >= 0 && l < (int)ft_strlen(temp))
		str[i] = '\n';
	return (str);
}

char	*get_end(char *temp)
{
	char	*tempbis;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	while (temp[i + n])
		n++;
	if (n > 1)
	{
		tempbis = calloc(n + 1, 1);
		n = 1;
		while (temp[i + n])
		{
			tempbis[n - 1] = temp[i + n];
			n++;
		}
	}
	else
		tempbis = NULL;
	free(temp);
	return (tempbis);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || fd > 1024 || !BUFFER_SIZE)
		return (NULL);
	temp = ft_read(fd, temp);
	if (!temp)
		return (NULL);
	line = get_line(temp);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	temp = get_end(temp);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	// 	// int	fd1;gnlTester/files/41_with_nl
// 	fd = open("gnlTester/files/41_with_nl", O_RDWR);
// 	while (i < 10)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			fprintf(stderr, "(NULL)\n");
// 		else
// 			fprintf(stderr, "gnl: %s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
