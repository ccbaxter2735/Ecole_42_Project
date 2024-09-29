/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:02:45 by terussar          #+#    #+#             */
/*   Updated: 2024/01/18 19:56:23 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_img(t_image *image, void *img, int x, int y)
{
	mlx_put_image_to_window(image->mlx, image->win, img,
		image->img_width * x, image->img_height * y);
}

void	draw_annexe(t_image *data, int steps, t_line *line, int color)
{
	int		i;
	float	x;
	float	y;

	x = line->ori.x;
	y = line->ori.y;
	i = -1;
	while (++i <= steps)
	{
		mlx_pixel_put(data->mlx, data->win,
			x, y, color);
		x += (line->p1.x - line->ori.x) / (float)steps;
		y += (line->p1.y - line->ori.y) / (float)steps;
	}
}

void	draw_line(t_image *data, t_line *line, int color)
{
	int	dx;
	int	dy;
	int	steps;

	dx = line->p1.x - line->ori.x;
	dy = line->p1.y - line->ori.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	draw_annexe(data, steps, line, color);
}

void	make_square(t_image *image, int x, int y, int color)
{
	int		i;
	int		j;
	t_line	line;

	ft_bzero(&line, sizeof(line));
	i = x - 4;
	j = y - 4;
	while (++i < x + 4)
	{
		j = y - 4;
		while (++j < y + 4)
			mlx_pixel_put(image->mlx, image->win, i, j, color);
	}
	line.ori.x = x;
	line.ori.y = y;
	line.p1.x = x + (image->dir_pos.pos_x + image->plane_pos.pos_x) * 32;
	line.p1.y = y + (image->dir_pos.pos_y + image->plane_pos.pos_y) * 32;
	draw_line(image, &line, 0x40B61B);
	line.p1.x = x + (image->dir_pos.pos_x - image->plane_pos.pos_x) * 32;
	line.p1.y = y + (image->dir_pos.pos_y - image->plane_pos.pos_y) * 32;
	draw_line(image, &line, 0x40B61B);
}
