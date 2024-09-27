/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mouv_ennemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:31:39 by terussar          #+#    #+#             */
/*   Updated: 2023/03/15 16:31:51 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_top_ennemy(t_data *data)
{
	if (data->map[data->pos_e.y - 1][data->pos_e.x] != '1'
		&& data->map[data->pos_e.y - 1][data->pos_e.x] != 'E' && data->playing)
	{
		if (!(data->map[data->pos_e.y - 1][data->pos_e.x] == 'P'))
		{
			data->map[data->pos_e.y - 1][data->pos_e.x] = 'A';
			print_img(data, data->img.img_ennemy_now, data->pos_e.x,
				data->pos_e.y - 1);
			data->map[data->pos_e.y][data->pos_e.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos_e.x, data->pos_e.y);
			data->pos_e.y = data->pos_e.y - 1;
		}
		else
		{
			ft_printf("Vous avez perdu !");
			data->playing = 0;
			lose_windows(data);
		}
	}
}

void	render_left_ennemy(t_data *data)
{
	if (data->map[data->pos_e.y][data->pos_e.x - 1] != '1'
		&& data->map[data->pos_e.y][data->pos_e.x - 1] != 'E' && data->playing)
	{
		if (!(data->map[data->pos_e.y][data->pos_e.x - 1] == 'P'))
		{
			data->map[data->pos_e.y][data->pos_e.x - 1] = 'A';
			print_img(data, data->img.img_ennemy_now, data->pos_e.x - 1,
				data->pos_e.y);
			data->map[data->pos_e.y][data->pos_e.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos_e.x, data->pos_e.y);
			data->pos_e.x = data->pos_e.x - 1;
		}
		else
		{
			ft_printf("Vous avez perdu !");
			data->playing = 0;
			lose_windows(data);
		}
	}
}

void	render_right_ennemy(t_data *data)
{
	if (data->map[data->pos_e.y][data->pos_e.x + 1] != '1'
		&& data->map[data->pos_e.y][data->pos_e.x + 1] != 'E' && data->playing)
	{
		if (!(data->map[data->pos_e.y][data->pos_e.x + 1] == 'P'))
		{
			data->map[data->pos_e.y][data->pos_e.x + 1] = 'A';
			print_img(data, data->img.img_ennemy_now, data->pos_e.x + 1,
				data->pos_e.y);
			data->map[data->pos_e.y][data->pos_e.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos_e.x, data->pos_e.y);
			data->pos_e.x = data->pos_e.x + 1;
		}
		else
		{
			ft_printf("Vous avez perdu !");
			data->playing = 0;
			lose_windows(data);
		}
	}
}

void	render_down_ennemy(t_data *data)
{
	if (data->map[data->pos_e.y + 1][data->pos_e.x] != '1'
		&& data->map[data->pos_e.y + 1][data->pos_e.x] != 'E' && data->playing)
	{
		if (!(data->map[data->pos_e.y + 1][data->pos_e.x] == 'P'))
		{
			data->map[data->pos_e.y + 1][data->pos_e.x] = 'A';
			print_img(data, data->img.img_ennemy_now, data->pos_e.x,
				data->pos_e.y + 1);
			data->map[data->pos_e.y][data->pos_e.x] = data->content.space;
			print_img(data, data->img.img_floor, data->pos_e.x, data->pos_e.y);
			data->pos_e.y = data->pos_e.y + 1;
		}
		else
		{
			ft_printf("Vous avez perdu !");
			data->playing = 0;
			lose_windows(data);
		}
	}
}

void	move_ennemy(t_data *data)
{
	int	diff_x;
	int	diff_y;

	diff_y = data->pos.y - data->pos_e.y;
	diff_x = data->pos.x - data->pos_e.x;
	if (diff_y <= 0 && ft_abs(diff_x) <= ft_abs(diff_y))
		render_top_ennemy(data);
	else if (diff_y >= 0 && ft_abs(diff_x) > ft_abs(diff_y))
		render_down_ennemy(data);
	else if (diff_x >= 0 && ft_abs(diff_y) <= ft_abs(diff_x))
		render_right_ennemy(data);
	else
		render_left_ennemy(data);
}
