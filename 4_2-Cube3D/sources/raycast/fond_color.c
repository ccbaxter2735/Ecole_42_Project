/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fond_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:01:19 by khle              #+#    #+#             */
/*   Updated: 2024/01/19 16:39:02 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_floor_ceilling(t_image *image)
{
	int	bpp;
	int	size_line;
	int	endian;

	bpp = 32;
	size_line = 0;
	endian = 1;
	image->screen_txt = malloc(sizeof(t_texture));
	if (!image->screen_txt)
		return (ft_clean(image), 0);
	image->screen_txt->content = mlx_new_image(image->mlx,
			image->size.width, image->size.height);
	if (!image->screen_txt->content)
	{
		write(2, "Error: mlx_new_image\n", 22);
		return (ft_clean(image), 0);
	}
	image->screen_txt->addr = (int *)mlx_get_data_addr
		(image->screen_txt->content, &bpp, &size_line, &endian);
	if (!image->screen_txt->addr)
	{
		write(2, "Error: mlx_get_data_addr\n", 26);
		return (ft_clean(image), 0);
	}
	return (1);
}

void	fill_floor_ceiling(t_image *image)
{
	int	i;

	i = -1;
	while (++i < ((image->size.height * image->size.width) / 2))
		image->screen_txt->addr[i] = image->map_game->ceiling;
	while (++i < (image->size.height * image->size.width))
		image->screen_txt->addr[i] = image->map_game->floor;
}

int	get_color(t_image *image, t_texture *wall, int y)
{
	int		color;
	double	wall_x;
	int		tex_x;
	int		tex_y;

	if (!image->side)
		wall_x = image->player_pos.pos_y
			+ image->wall_dist * image->ray_dir.pos_y;
	else
		wall_x = image->player_pos.pos_x
			+ image->wall_dist * image->ray_dir.pos_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)wall->size.width);
	if (!image->side && image->ray_dir.pos_x > 0)
		tex_x = wall->size.width - tex_x - 1;
	if (image->side && image->ray_dir.pos_y < 0)
		tex_x = wall->size.width - tex_x - 1;
	tex_y = (((y * 2 - image->size.height + image->line_hight)
				* wall->size.height) / image->line_hight) / 2;
	color = wall->addr[(int)tex_x + (tex_y * wall->size.width)];
	return (color);
}
