/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:32:24 by terussar          #+#    #+#             */
/*   Updated: 2024/01/18 19:56:30 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_img_background(t_image *image)
{
	image->img_height = 32;
	image->img_width = 32;
	image->img_black = mlx_xpm_file_to_image(image->mlx,
			"txt/black.xpm", &image->img_width, &image->img_height);
	image->img_white = mlx_xpm_file_to_image(image->mlx,
			"txt/white.xpm", &image->img_width, &image->img_height);
}

int	get_h(t_image *image)
{
	int	i;

	i = 0;
	while (image->map_game->map_game[i])
		i++;
	return (i);
}

int	get_w(t_image *image, int j)
{
	int	i;

	i = 0;
	if (image->map_game->map_game[j])
	{
		while (image->map_game->map_game[j][i])
			i++;
	}
	return (i);
}

void	print_background(t_image *image, char **map)
{
	int	i;
	int	j;
	int	plx;
	int	ply;

	j = (int)image->player_pos.pos_y - 3;
	ply = -1;
	while (++ply < 5 && ++j < ((int)image->player_pos.pos_y + 3))
	{
		plx = -1;
		i = (int)image->player_pos.pos_x - 3;
		while (++plx < 5 && ++i < ((int)image->player_pos.pos_x + 3))
		{
			if (j < 0 || i < 0 || j >= get_h(image) || i >= get_w(image, j))
				print_img(image, image->img_white, plx, ply);
			else
			{
				if (map[j][i] == '1' || map[j][i] == ' ')
					print_img(image, image->img_white, plx, ply);
				if (map[j][i] == '0' || map[j][i] == 'X')
					print_img(image, image->img_black, plx, ply);
			}
		}
	}
	make_square(image, 80, 80, 0xD24A2C);
}
