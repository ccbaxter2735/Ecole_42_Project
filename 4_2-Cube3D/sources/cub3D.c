/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:27:38 by le                #+#    #+#             */
/*   Updated: 2024/01/19 16:38:04 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_map_game(t_map *map_game)
{
	map_game->north = NULL;
	map_game->west = NULL;
	map_game->south = NULL;
	map_game->east = NULL;
	map_game->player_x = 0;
	map_game->player_y = 0;
	map_game->floor = -1;
	map_game->ceiling = -1;
}

void	ft_free_map(t_map *map_game)
{	
	if (map_game && map_game->north)
		free(map_game->north);
	if (map_game && map_game->west)
		free(map_game->west);
	if (map_game && map_game->south)
		free(map_game->south);
	if (map_game && map_game->east)
		free(map_game->east);
	if (map_game)
		free(map_game);
}

int	main(int ac, char **av)
{
	t_map	*map_game;
	t_image	image;
	char	**map;

	if (ac != 2 || !av || !av[1])
		return (write(2, "ERROR: Number of args\n", 23), 1);
	map_game = malloc(sizeof(t_map));
	if (!map_game)
		return (write(2, "ERROR: Malloc\n", 15), 1);
	init_map_game(map_game);
	map = ft_parsing(av[1], map_game);
	if (!map)
		return (ft_free_map(map_game), 1);
	map_game->map_game = map;
	init_mlx(map_game, &image);
	ft_free_tab(map);
	ft_free_map(map_game);
	return (0);
}
