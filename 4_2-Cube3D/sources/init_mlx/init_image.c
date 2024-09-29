/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:49:01 by le                #+#    #+#             */
/*   Updated: 2024/01/18 20:02:25 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_texture	*set_texture(t_image *image, char *wall_image)
{
	t_texture	*texture;
	int			bpp;
	int			endian;
	int			size_line;

	bpp = 32;
	endian = 1;
	size_line = 0;
	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (ft_clean(image), NULL);
	ft_memset(texture, 0, sizeof(texture));
	texture->path = wall_image;
	texture->content = mlx_xpm_file_to_image(image->mlx,
			texture->path, &texture->size.width, &texture->size.height);
	if (!texture->content)
	{
		write(2, "ERROR: image loading\n", 22);
		return (clean_image(image, texture), ft_clean(image), NULL);
	}
	texture->addr = (int *)mlx_get_data_addr(texture->content,
			&bpp, &size_line, &endian);
	return (texture);
}

int	init_wall_image(t_map *map_game, t_image *image)
{
	ft_memset(image, 0, sizeof(t_image));
	image->map_game = map_game;
	image->mlx = mlx_init();
	image->size.height = SCRHGHT;
	image->size.width = SCRWDTH;
	set_img_background(image);
	image->north = set_texture(image, map_game->north);
	image->west = set_texture(image, map_game->west);
	image->south = set_texture(image, map_game->south);
	image->east = set_texture(image, map_game->east);
	return (0);
}

void	init_default_structure(t_map *map_game, t_image *image)
{
	image->player_pos.pos_x = map_game->player_x + 0.5;
	image->player_pos.pos_y = map_game->player_y + 0.5;
	image->dir_pos.pos_x = 0;
	image->dir_pos.pos_y = -1;
	image->plane_pos.pos_x = FOV;
	image->plane_pos.pos_y = 0;
}

void	init_stucture(t_map *map_game, t_image *image)
{
	init_default_structure(map_game, image);
	if (map_game->player_dir == 'E')
	{
		image->dir_pos.pos_x = 1;
		image->dir_pos.pos_y = 0;
		image->plane_pos.pos_x = 0;
		image->plane_pos.pos_y = FOV;
	}
	else if (map_game->player_dir == 'W')
	{
		image->dir_pos.pos_x = -1;
		image->dir_pos.pos_y = 0;
		image->plane_pos.pos_x = 0;
		image->plane_pos.pos_y = -FOV;
	}
	else if (map_game->player_dir == 'S')
	{
		image->dir_pos.pos_x = 0;
		image->dir_pos.pos_y = 1;
		image->plane_pos.pos_x = -FOV;
		image->plane_pos.pos_y = 0;
	}
}

int	init_mlx(t_map *map_game, t_image *image)
{
	init_wall_image(map_game, image);
	init_stucture(map_game, image);
	image->win = mlx_new_window(image->mlx, SCRWDTH,
			SCRHGHT, "CUB3D");
	mlx_loop_hook(image->mlx, &raycast, image);
	mlx_hook(image->win, KeyPress, KeyPressMask, &key_press, image);
	mlx_hook(image->win, MotionNotify, PointerMotionMask, &ft_mouse, image);
	mlx_hook(image->win, DestroyNotify, StructureNotifyMask, &end, image);
	mlx_loop(image->mlx);
	end(image);
	return (0);
}
