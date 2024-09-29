/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le <le@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 03:47:47 by khle              #+#    #+#             */
/*   Updated: 2024/01/23 08:40:28 by le               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*open_map_file(int fd)
{
	char	*map;
	char	*buff;
	int		i;

	map = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(buff), NULL);
		buff[i] = 0;
		map = ft_strjoin2(map, buff);
	}
	free(buff);
	close(fd);
	return (map);
}

int	ft_find1(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(to_find);
	if (!str || !to_find)
		return (0);
	while (str[i] == ' ')
		i++;
	while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
		j++;
	if (j == len)
		return (1);
	return (0);
}

int	ft_find2(char **str, char *tofind, int *pos)
{
	int	i;

	i = 0;
	if (!str || !tofind)
		return (-1);
	while (str[i])
	{
		if (ft_find1(str[i], tofind))
			return (*pos = i, i);
		i++;
	}
	return (*pos = -1, -1);
}

char	*ft_link_image(char *str)
{
	int		i;
	int		len;
	char	*image;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	len = ft_strlen(str) - i;
	if (len <= 0 || !str[i] || str[i] != '.')
		return (NULL);
	image = malloc (sizeof(char) * (len + 1));
	if (!image)
		return (NULL);
	len = 0;
	while (str[i + len])
	{
		image[len] = str[i + len];
		len++;
	}
	image[len] = 0;
	return (image);
}

int	check_line(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	ft_find2(map, "1", &i);
	i -= 1;
	while (i >= 0)
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] && map[i][j] != ' ')
			count += 1;
		i--;
	}
	return (count);
}
