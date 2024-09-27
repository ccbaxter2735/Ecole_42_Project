/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:01:06 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 17:19:28 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// verif nombre de collectible restant
int	chk_collect(t_data *data)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

void	destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_wallchd);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wallchg);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wallcbg);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wallcbd);
	mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerb.img1);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerb.img2);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerb.img3);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerh.img1);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerh.img2);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerh.img3);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerg.img1);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerg.img2);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerg.img3);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerd.img1);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerd.img2);
	mlx_destroy_image(data->mlx_ptr, data->img.img_playerd.img3);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ennemy.img1);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ennemy.img2);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ennemy.img3);
	mlx_destroy_image(data->mlx_ptr, data->img.win_windows);
	mlx_destroy_image(data->mlx_ptr, data->img.los_windows);
	mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
}

// fonction mettant fin au jeu (free & destroy)
int	end(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wallint);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wallg);
		mlx_destroy_image(data->mlx_ptr, data->img.img_walld);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wallbas);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wallh);
		destroy_image(data);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

// fonction de deplacement et fin de jeu
int	key_press(int keysym, t_data *data)
{
	stop_game(keysym, data);
	if (!data->playing)
		return (0);
	data->img.img_pla_ennemy = &data->img.img_ennemy;
	if (keysym == XK_w)
	{
		data->img.img_pla = &data->img.img_playerh;
		render_top(data);
	}
	if (keysym == XK_d)
	{
		data->img.img_pla = &data->img.img_playerd;
		render_right(data);
	}
	if (keysym == XK_a)
	{
		data->img.img_pla = &data->img.img_playerg;
		render_left(data);
	}
	if (keysym == XK_s)
	{
		data->img.img_pla = &data->img.img_playerb;
		render_down(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("Error\nArgument missing\n");
	else
	{
		ft_bzero(&data, sizeof(data));
		data.mlx_ptr = mlx_init();
		set_content(&(data.content));
		data.map = map_init(av, &data);
		if (data.map != NULL)
		{
			find_player(&data);
			find_ennemy(&data);
			set_img_background(&data);
			set_img_player(&data);
			set_img_ennemy(&data);
			print_map(&data);
		}
		else
			end(&data);
	}
	return (0);
}
