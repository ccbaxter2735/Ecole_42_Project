/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:55:38 by terussar          #+#    #+#             */
/*   Updated: 2024/01/18 20:22:56 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	end(t_image *image)
{
	clean_image(image, image->north);
	clean_image(image, image->south);
	clean_image(image, image->east);
	clean_image(image, image->west);
	clean_image(image, image->screen_txt);
	mlx_destroy_image(image->mlx, image->img_black);
	mlx_destroy_image(image->mlx, image->img_white);
	if (image->map_game->map_game)
		ft_free_tab(image->map_game->map_game);
	if (image->map_game)
		ft_free_map(image->map_game);
	mlx_destroy_window(image->mlx, image->win);
	mlx_destroy_display(image->mlx);
	free(image->mlx);
	exit(0);
	return (0);
}
