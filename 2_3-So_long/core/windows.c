/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:45:09 by terussar          #+#    #+#             */
/*   Updated: 2023/03/10 15:50:03 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win_windows(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.win_windows,
		((data->width * 64) / 2 - 160), (data->height * 64) / 2 - 96);
}

void	lose_windows(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.los_windows,
		((data->width * 64) / 2 - 160), (data->height * 64) / 2 - 96);
}
