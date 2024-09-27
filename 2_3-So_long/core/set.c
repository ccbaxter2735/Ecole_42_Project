/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:12:51 by terussar          #+#    #+#             */
/*   Updated: 2023/03/13 12:21:10 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(t_cnt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_c = 0;
	content->count_e = 0;
}

void	set_img_background(t_data *data)
{
	data->img.height = 64;
	data->img.width = 64;
	data->height_win = 192;
	data->width_win = 320;
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, "src/space.xpm",
			&data->img.height, &data->img.height);
	data->img.img_wallint = mlx_xpm_file_to_image(data->mlx_ptr, "src/wall.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_wallg = mlx_xpm_file_to_image(data->mlx_ptr, "src/ct_g.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_walld = mlx_xpm_file_to_image(data->mlx_ptr, "src/ct_d.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_wallbas = mlx_xpm_file_to_image(data->mlx_ptr, "src/bas.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_wallh = mlx_xpm_file_to_image(data->mlx_ptr, "src/haut.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_wallcbd = mlx_xpm_file_to_image(data->mlx_ptr, "src/c_d.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_wallcbg = mlx_xpm_file_to_image(data->mlx_ptr, "src/c_g.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_wallchd = mlx_xpm_file_to_image(data->mlx_ptr, "src/chd.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_wallchg = mlx_xpm_file_to_image(data->mlx_ptr, "src/chg.xpm",
			&(data->img.width), &(data->img.height));
}

void	set_img_player(t_data *data)
{
	data->img.img_playerb.img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerb.img2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply2.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerb.img3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply3.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerh.img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_h.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerh.img2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_h2.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerh.img3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_h3.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerg.img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_g.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerg.img2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_g2.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerg.img3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_g3.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerd.img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_d.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerd.img2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_d2.xpm", &(data->img.width), &(data->img.height));
	data->img.img_playerd.img3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/player/ply_d3.xpm", &(data->img.width), &(data->img.height));
	data->img.img_pla = &data->img.img_playerb;
}

void	set_img_ennemy(t_data *data)
{
	data->img.img_p_n = &data->img.img_pla->img1;
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr, "src/cllt.xpm",
			&(data->img.width), &(data->img.height));
	data->img.img_ennemy.img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/ennemy/ennemyd1.xpm", &(data->img.width), &(data->img.height));
	data->img.img_ennemy.img2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/ennemy/ennemyd2.xpm", &(data->img.width), &(data->img.height));
	data->img.img_ennemy.img3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"src/ennemy/ennemyd3.xpm", &(data->img.width), &(data->img.height));
	data->img.img_pla_ennemy = &data->img.img_ennemy;
	data->img.img_ennemy_now = &data->img.img_pla_ennemy->img1;
	data->img.win_windows = mlx_xpm_file_to_image(data->mlx_ptr, "src/w_w.xpm",
			&data->width_win, &data->height_win);
	data->img.los_windows = mlx_xpm_file_to_image(data->mlx_ptr, "src/l_w.xpm",
			&data->width_win, &data->height_win);
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "src/exit.xpm",
			&(data->img.width), &(data->img.height));
}
