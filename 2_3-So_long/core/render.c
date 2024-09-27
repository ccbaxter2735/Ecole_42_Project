/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:33:15 by terussar          #+#    #+#             */
/*   Updated: 2023/03/13 12:01:11 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}

void	fill_image_wall(int i, int j, t_data *data)
{
	if (i == 0 && j == 0)
		print_img(data, data->img.img_wallchg, i, j);
	else if (i == 0 && j == data->height - 1)
		print_img(data, data->img.img_wallcbg, i, j);
	else if (i == data->width - 1 && j == 0)
		print_img(data, data->img.img_wallchd, i, j);
	else if (i == data->width - 1 && j == data->height - 1)
		print_img(data, data->img.img_wallcbd, i, j);
	else if (i == 0 && (j != 0 || j != data->height - 1))
		print_img(data, data->img.img_wallg, i, j);
	else if (j == 0 && (i != 0 || i != data->width))
		print_img(data, data->img.img_wallh, i, j);
	else if (i == data->width - 1)
		print_img(data, data->img.img_walld, i, j);
	else if (j == data->height - 1)
		print_img(data, data->img.img_wallbas, i, j);
	else
		print_img(data, data->img.img_wallint, i, j);
}

void	print_background(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] != '\0' && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == '1')
				fill_image_wall(i, j, data);
			if (data->map[j][i] == 'C')
				print_img(data, data->img.img_collect, i, j);
			if (data->map[j][i] == 'E')
				print_img(data, data->img.img_exit, i, j);
			if (data->map[j][i] == '0')
				print_img(data, data->img.img_floor, i, j);
			i++;
		}
		j++;
	}
}

void	print_other(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] != '\0' && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == 'P')
				print_img(data, data->img.img_p_n, i, j);
			if (data->map[j][i] == 'A')
				print_img(data, data->img.img_ennemy_now, i, j);
			i++;
		}
		j++;
	}
}

int	render(t_data *data)
{
	data->compt++;
	if (data->compt > 10000)
	{
		data->img.img_p_n = data->img.img_pla->img3;
		data->img.img_ennemy_now = data->img.img_pla_ennemy->img3;
	}
	else if (data->compt > 6000)
	{
		data->img.img_p_n = data->img.img_pla->img2;
		data->img.img_ennemy_now = data->img.img_pla_ennemy->img2;
	}
	else
	{
		data->img.img_p_n = data->img.img_pla->img1;
		data->img.img_ennemy_now = data->img.img_pla_ennemy->img1;
	}
	if (data->compt > 14000)
		data->compt = 0;
	if (data->playing)
		print_other(data);
	return (0);
}
