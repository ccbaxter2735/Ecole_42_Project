/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:02:55 by le                #+#    #+#             */
/*   Updated: 2024/01/18 19:11:48 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	raycast(void *para)
{
	t_image	*image;
	int		x;

	x = -1;
	image = (t_image *)para;
	if (!init_floor_ceilling(image))
		return (-1);
	fill_floor_ceiling(image);
	while (++x < image->size.width)
	{
		init_element(image, x);
		calculate_side_dist(image);
		ft_dda(image);
		calculate_wall_dist(image);
		fill_image(image, x);
	}
	mlx_put_image_to_window(image->mlx, image->win,
		image->screen_txt->content, 0, 0);
	print_background(image, image->map_game->map_game);
	mlx_destroy_image(image->mlx, image->screen_txt->content);
	free(image->screen_txt);
	image->screen_txt = NULL;
	return (0);
}
