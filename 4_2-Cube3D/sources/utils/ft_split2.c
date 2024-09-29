/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le <le@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:58:00 by khle              #+#    #+#             */
/*   Updated: 2024/01/23 09:43:34 by le               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split2(char *s, char c)
{
	char	**list;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	list = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!list || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			list[j] = word_dup(s, start, i);
			j++;
			start = -1;
		}
		i++;
	}
	list[j] = 0;
	return (list);
}

int	check_name_image1(t_map *map_game)
{
	int	i;

	i = ft_strlen(map_game->north);
	while (i > 0 && map_game->north[i - 1] == ' ')
		i = i - 1;
	map_game->north = copy_new(map_game->north, &i);
	if (i < 5 || map_game->north[i - 1] != 'm' || map_game->north[i - 2] != 'p'
		|| map_game->north[i - 3] != 'x' || map_game->north[i - 4] != '.'
		|| check_open_image(map_game->north) < 0)
		return (-1);
	i = ft_strlen(map_game->south);
	while (i > 0 && map_game->south[i - 1] == ' ')
		i = i - 1;
	map_game->south = copy_new(map_game->south, &i);
	if (i < 5 || map_game->south[i - 1] != 'm' || map_game->south[i - 2] != 'p'
		|| map_game->south[i - 3] != 'x' || map_game->south[i - 4] != '.'
		|| check_open_image(map_game->south) < 0)
		return (-1);
	return (0);
}
