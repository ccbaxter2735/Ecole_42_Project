/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le <le@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:27:41 by terussar          #+#    #+#             */
/*   Updated: 2024/01/23 08:15:27 by le               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_check_map_border(char **map, int y, int x, int *exit)
{
	if (!map[y] || !map[y][x] || x < 0 || y < 0 || map[y][x] == ' ')
	{
		*exit = 2;
		return ;
	}
	if (map[y][x] != '0')
		return ;
	map[y][x] = 'X';
	ft_check_map_border(map, y - 1, x, exit);
	ft_check_map_border(map, y + 1, x, exit);
	ft_check_map_border(map, y, x - 1, exit);
	ft_check_map_border(map, y, x + 1, exit);
}

int	copy_map(char ***map, int start, int len)
{
	int		i;
	char	**final_map;

	i = 0;
	final_map = malloc(sizeof(char *) * (len + 1));
	if (!final_map)
		return (ft_free_tab(*map), write(2, "ERROR: Malloc\n", 15), -1);
	while ((*map)[start + i])
	{
		final_map[i] = ft_strdup2((*map)[start + i]);
		if (!final_map[i])
		{
			ft_free_tab(*map);
			ft_free_tab(final_map);
			return (write(2, "ERROR: Malloc\n", 15), -1);
		}
		i++;
	}
	final_map[i] = 0;
	ft_free_tab(*map);
	*map = final_map;
	return (0);
}

char	**ft_final_map(char **map, t_map *map_game)
{
	int		i;
	int		count;
	int		start;

	i = 0;
	count = 0;
	if (ft_find2(map, "1", &i) < 0)
		return (ft_free_tab(map), write(2, "ERROR: Charac\n", 15), NULL);
	start = i - 1;
	while (map[++start])
	{
		if (ft_check_charac(map[start], &count, map_game) < 0)
			return (ft_free_tab(map), write(2, "ERROR: Charac\n", 15), NULL);
		if (count != 0 && map_game->player_y == 0)
			map_game->player_y = start - i;
	}
	if (count != 1 || map_game->player_y < 0)
		return (ft_free_tab(map), write(2, "ERROR: Invalid map\n", 20), NULL);
	if (copy_map(&map, i, start - i) < 0)
		return (NULL);
	map[map_game->player_y][map_game->player_x] = '0';
	ft_check_map_border(map, map_game->player_y, map_game->player_x, &count);
	if (count == 2)
		return (ft_free_tab(map), write(2, "ERROR: Invalid map\n", 20), NULL);
	return (map);
}

int	check_map_name(char *av1)
{
	int		len;

	len = ft_strlen(av1);
	if (av1[len - 1] != 'b' || av1[len - 2] != 'u' || av1[len - 3] != 'c'
		|| av1[len - 4] != '.' || len < 5)
		return (write(2, "ERROR: Map name\n", 17), 0);
	return (1);
}

char	**ft_parsing(char *av1, t_map *map_game)
{
	int		fd;
	char	*str_map;
	char	**map;

	if (check_map_name(av1) == 0)
		return (NULL);
	fd = open(av1, O_RDONLY);
	if (fd < 0)
		return (write(2, "ERROR: Cannot open file\n", 25), NULL);
	str_map = open_map_file(fd);
	map = ft_split2(str_map, '\n');
	free(str_map);
	if (!map)
		return (write(2, "ERROR: Malloc\n", 15), NULL);
	if (ft_check_image(map, map_game) < 0)
		return (ft_free_tab(map), NULL);
	if (ft_check_color(map, map_game) < 0)
		return (ft_free_tab(map), NULL);
	if (check_line(map) > 6)
		return (write(2, "ERROR: Line\n", 13), ft_free_tab(map), NULL);
	map = ft_final_map(map, map_game);
	if (!map)
		return (NULL);
	return (map);
}
