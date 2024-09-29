/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 04:53:48 by khle              #+#    #+#             */
/*   Updated: 2024/01/18 18:33:15 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_element(t_image *image, int x)
{
	image->map.x = image->player_pos.pos_x;
	image->map.y = image->player_pos.pos_y;
	image->hit = 0;
	image->camera_x = (2 * x / (double)image->size.width) - 1;
	image->ray_dir.pos_x = image->dir_pos.pos_x
		+ (image->plane_pos.pos_x * image->camera_x);
	image->ray_dir.pos_y = image->dir_pos.pos_y
		+ (image->plane_pos.pos_y * image->camera_x);
	image->delta_dist.pos_x = fabs(1 / image->ray_dir.pos_x);
	image->delta_dist.pos_y = fabs(1 / image->ray_dir.pos_y);
}

void	calculate_side_dist(t_image *image)
{
	if (image->ray_dir.pos_x < 0)
	{
		image->step.x = -1;
		image->size_dist.pos_x = (image->player_pos.pos_x - image->map.x)
			* image->delta_dist.pos_x;
	}
	else
	{
		image->step.x = 1;
		image->size_dist.pos_x = (image->map.x + 1 - image->player_pos.pos_x)
			* image->delta_dist.pos_x;
	}
	if (image->ray_dir.pos_y < 0)
	{
		image->step.y = -1;
		image->size_dist.pos_y = (image->player_pos.pos_y - image->map.y)
			* image->delta_dist.pos_y;
	}
	else
	{
		image->step.y = 1;
		image->size_dist.pos_y = (image->map.y + 1 - image->player_pos.pos_y)
			* image->delta_dist.pos_y;
	}
}

void	ft_dda(t_image *image)
{
	while (!image->hit)
	{
		if (image->size_dist.pos_x < image->size_dist.pos_y)
		{
			image->size_dist.pos_x += image->delta_dist.pos_x;
			image->map.x += image->step.x;
			image->side = 0;
		}
		else
		{
			image->size_dist.pos_y += image->delta_dist.pos_y;
			image->map.y += image->step.y;
			image->side = 1;
		}
		if (image->map.x < 0)
			image->map.x = 0;
		if (image->map.y < 0)
			image->map.y = 0;
		if (image->map_game->map_game[image->map.y][image->map.x] == '1')
			image->hit = 1;
	}
}

void	calculate_wall_dist(t_image *image)
{
	if (image->side == 0)
		image->wall_dist = (image->size_dist.pos_x - image->delta_dist.pos_x);
	else
		image->wall_dist = (image->size_dist.pos_y - image->delta_dist.pos_y);
	image->line_hight = (int)(image->size.height / image->wall_dist);
	image->draw_start = -(image->line_hight / 2) + (image->size.height / 2);
	if (image->draw_start < 0)
		image->draw_start = 0;
	image->draw_end = (image->line_hight / 2) + (image->size.height / 2);
	if (image->draw_end >= image->size.height)
		image->draw_end = image->size.height - 1;
}

void	fill_image(t_image *image, int x)
{
	int			start;
	int			end;
	int			color;
	t_texture	*wall;

	start = image->draw_start;
	end = image->draw_end;
	if (image->ray_dir.pos_x > 0 && image->side == 0)
		wall = image->east;
	else if (image->ray_dir.pos_x < 0 && image->side == 0)
		wall = image->west;
	else if (image->ray_dir.pos_y > 0 && image->side == 1)
		wall = image->south;
	else
		wall = image->north;
	while (start <= end)
	{
		color = get_color(image, wall, start);
		image->screen_txt->addr[(image->size.width * start) + x] = color;
		start += 1;
	}
}
