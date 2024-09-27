/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mouv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:17:36 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 16:33:33 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win_screen(t_data *data)
{
	if (chk_collect(data) == 0)
	{
		ft_printf("c'est gagne en %d coups\n", data->count);
		win_windows(data);
		data->playing = 0;
	}
}

void	render_top(t_data *data)
{
	char	*str;

	if (data->pos_e.x != 0)
		move_ennemy(data);
	if (data->map[data->pos.y - 1][data->pos.x] != '1'
		&& data->map[data->pos.y - 1][data->pos.x] != 'A' && data->playing)
	{
		if (!(data->map[data->pos.y - 1][data->pos.x] == data->content.exit))
		{
			data->map[data->pos.y - 1][data->pos.x] = data->content.player;
			print_img(data, data->img.img_p_n, data->pos.x, data->pos.y - 1);
			data->map[data->pos.y][data->pos.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count++;
			str = ft_itoa(data->count);
			print_img(data, data->img.img_wallh, data->width / 2, 0);
			mlx_string_put(data->mlx_ptr, data->mlx_win,
				((data->width * 64) / 2), 64 / 2, 0, str);
			free(str);
			data->pos.y = data->pos.y - 1;
			ft_printf("count: %d\n", data->count);
		}
		else
			win_screen(data);
	}
}

void	render_left(t_data *data)
{
	char	*str;

	if (data->pos_e.x != 0)
		move_ennemy(data);
	if (data->map[data->pos.y][data->pos.x - 1] != '1'
		&& data->map[data->pos.y][data->pos.x - 1] != 'A' && data->playing)
	{
		if (!(data->map[data->pos.y][data->pos.x - 1] == data->content.exit))
		{
			data->map[data->pos.y][data->pos.x - 1] = data->content.player;
			print_img(data, data->img.img_p_n, data->pos.x - 1, data->pos.y);
			data->map[data->pos.y][data->pos.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count++;
			str = ft_itoa(data->count);
			print_img(data, data->img.img_wallh, data->width / 2, 0);
			mlx_string_put(data->mlx_ptr, data->mlx_win,
				((data->width * 64) / 2), 64 / 2, 0, str);
			free(str);
			data->pos.x = data->pos.x - 1;
			ft_printf("count: %d\n", data->count);
		}
		else
			win_screen(data);
	}
}

void	render_right(t_data *data)
{
	char	*str;

	if (data->pos_e.x != 0)
		move_ennemy(data);
	if (data->map[data->pos.y][data->pos.x + 1] != '1'
		&& data->map[data->pos.y][data->pos.x + 1] != 'A' && data->playing)
	{
		if (!(data->map[data->pos.y][data->pos.x + 1] == data->content.exit))
		{
			data->map[data->pos.y][data->pos.x + 1] = data->content.player;
			print_img(data, data->img.img_p_n, data->pos.x + 1, data->pos.y);
			data->map[data->pos.y][data->pos.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count++;
			str = ft_itoa(data->count);
			print_img(data, data->img.img_wallh, data->width / 2, 0);
			mlx_string_put(data->mlx_ptr, data->mlx_win,
				((data->width * 64) / 2), 64 / 2, 0, str);
			free(str);
			data->pos.x = data->pos.x + 1;
			ft_printf("count: %d\n", data->count);
		}
		else
			win_screen(data);
	}
}

void	render_down(t_data *data)
{
	char	*str;

	if (data->pos_e.x != 0)
		move_ennemy(data);
	if (data->map[data->pos.y + 1][data->pos.x] != '1'
		&& data->map[data->pos.y + 1][data->pos.x] != 'A' && data->playing)
	{
		if (!(data->map[data->pos.y + 1][data->pos.x] == data->content.exit))
		{
			data->map[data->pos.y + 1][data->pos.x] = data->content.player;
			print_img(data, data->img.img_p_n, data->pos.x, data->pos.y + 1);
			data->map[data->pos.y][data->pos.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos.x, data->pos.y);
			data->count++;
			str = ft_itoa(data->count);
			print_img(data, data->img.img_wallh, data->width / 2, 0);
			mlx_string_put(data->mlx_ptr, data->mlx_win,
				((data->width * 64) / 2), 64 / 2, 0, str);
			free(str);
			data->pos.y = data->pos.y + 1;
			ft_printf("count: %d\n", data->count);
		}
		else
			win_screen(data);
	}
}
