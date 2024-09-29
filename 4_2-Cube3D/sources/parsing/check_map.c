/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:30:40 by khle              #+#    #+#             */
/*   Updated: 2024/01/23 14:08:38 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_name_image(t_map *map_game)
{
	int	i;

	if (check_name_image1(map_game))
		return (-1);
	i = ft_strlen(map_game->west);
	while (i > 0 && map_game->west[i - 1] == ' ')
		i = i - 1;
	map_game->west = copy_new(map_game->west, &i);
	if (i < 5 || map_game->west[i - 1] != 'm' || map_game->west[i - 2] != 'p'
		|| map_game->west[i - 3] != 'x' || map_game->west[i - 4] != '.'
		|| check_open_image(map_game->west) < 0)
		return (-1);
	i = ft_strlen(map_game->east);
	while (i > 0 && map_game->east[i - 1] == ' ')
		i = i - 1;
	map_game->east = copy_new(map_game->east, &i);
	if (i < 5 || map_game->east[i - 1] != 'm' || map_game->east[i - 2] != 'p'
		|| map_game->east[i - 3] != 'x' || map_game->east[i - 4] != '.'
		|| check_open_image(map_game->east) < 0)
		return (-1);
	return (0);
}

int	ft_check_image(char **map, t_map *game)
{
	int	i;

	i = 0;
	if (ft_find2(map, "NO ", &i) >= 0)
		game->north = ft_link_image(map[i]);
	else
		return (write(2, "ERROR: Path name\n", 17), -1);
	if (ft_find2(map, "WE ", &i) >= 0)
		game->west = ft_link_image(map[i]);
	else
		return (write(2, "ERROR: Path name\n", 17), -1);
	if (ft_find2(map, "SO ", &i) >= 0)
		game->south = ft_link_image(map[i]);
	else
		return (write(2, "ERROR: Path name\n", 17), -1);
	if (ft_find2(map, "EA ", &i) >= 0)
		game->east = ft_link_image(map[i]);
	else
		return (write(2, "ERROR: Path name\n", 17), -1);
	if (check_name_image(game) < 0)
		return (write(2, "ERROR: Path name\n", 17), -1);
	return (0);
}

int	ft_color_cf(char *str)
{
	int	red;
	int	green;
	int	blue;
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	i = i + 2;
	red = ft_atoi2(str, &i);
	i++;
	green = ft_atoi2(str, &i);
	i++;
	blue = ft_atoi2(str, &i);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] != ' ')
		return (-1);
	if (red < 0 || green < 0 || blue < 0 || red > 255
		|| green > 255 || blue > 255)
		return (-1);
	return (red << 16 | green << 8 | blue);
}

int	ft_check_color(char **map, t_map *map_game)
{
	int	i;

	i = 0;
	if (ft_find2(map, "F ", &i) >= 0)
		map_game->floor = ft_color_cf(map[i]);
	if (ft_find2(map, "C ", &i) >= 0)
		map_game->ceiling = ft_color_cf(map[i]);
	if (map_game->floor < 0 || map_game->ceiling < 0)
		return (write(2, "ERROR: Color\n", 14), -1);
	return (0);
}

int	ft_check_charac(char *str, int *count, t_map *map_game)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			*count += 1;
			map_game->player_x = i;
			map_game->player_dir = str[i];
		}
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W'
			|| str[i] == '0' || str[i] == '1' || str[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (0);
}
