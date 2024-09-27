/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:25:21 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 10:06:46 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_case(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map[++j])
	{
		i = 0;
		while (data->map[j][i] != '\0' && data->map[j][i] != '\n')
		{
			if (data->map[j][i] != 'E' && data->map[j][i] != 'P'
				&& data->map[j][i] != 'C' && data->map[j][i] != '0'
				&& data->map[j][i] != '1' && data->map[j][i] != 'A')
			{
				ft_error("Error\nUndefined character inside the map\n");
				return (-1);
			}
			i++;
		}
	}
	return (0);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P'
		|| map[y][x] == 'A' || map[y][x] == 'C')
	{
		if (map[y][x] == '0')
			map[y][x] = '2';
		if (map[y][x] == 'C')
			map[y][x] = '3';
		if (map[y][x] == 'P')
			map[y][x] = '4';
		flood_fill(map, x + 1, y);
		flood_fill(map, x, y + 1);
		flood_fill(map, x - 1, y);
		flood_fill(map, x, y - 1);
	}
}

int	check_flood(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[++j])
	{
		i = 0;
		while (data->map[j][i] != '\0' && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == 'E')
			{
				if (data->map[j][i + 1] == '2' || data->map[j][i - 1] == '2'
					|| data->map[j - 1][i] == '2' || data->map[j + 1][i] == '2'
					|| data->map[j][i + 1] == '3' || data->map[j][i - 1] == '3'
					|| data->map[j - 1][i] == '3' || data->map[j + 1][i] == '3'
					|| data->map[j][i + 1] == '4' || data->map[j][i - 1] == '4'
					|| data->map[j - 1][i] == '4' || data->map[j + 1][i] == '4')
					return (0);
				break ;
			}
			i++;
		}
	}
	ft_error("Error\nNo path between exit and player\n");
	return (-1);
}

int	check_collectible(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[++j])
	{
		i = 0;
		while (data->map[j][i] != '\0' && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == 'C')
			{
				ft_error("Error\nNo path between collectible and player\n");
				return (-1);
			}
			i++;
		}
	}
	return (0);
}

void	recover_map(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map[++j])
	{
		i = 0;
		while (data->map[j][i] != '\0' && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == '2')
				data->map[j][i] = '0';
			if (data->map[j][i] == '3')
				data->map[j][i] = 'C';
			if (data->map[j][i] == '4')
				data->map[j][i] = 'P';
			i++;
		}
	}
}
