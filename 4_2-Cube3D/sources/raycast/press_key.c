/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:37:02 by terussar          #+#    #+#             */
/*   Updated: 2024/01/18 20:19:47 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	key_press1(char c, t_image *image, double y, double x)
{
	char	**m;
	double	dir_x;
	double	dir_y;

	m = image->map_game->map_game;
	dir_x = image->dir_pos.pos_x * 0.1;
	dir_y = image->dir_pos.pos_y * 0.1;
	if (m[(int)y][(int)x] == 'X')
	{
		if ((c == 'w' && m[(int)(y + dir_y)][(int)(x + dir_x)] != '1')
			|| (c == 'd' && m[(int)(y + dir_x)][(int)(x - dir_y)] != '1')
			|| (c == 'a' && m[(int)(y - dir_x)][(int)(x + dir_y)] != '1')
			|| (c == 's' && m[(int)(y - dir_y)][(int)(x - dir_x)] != '1'))
		{
			image->player_pos.pos_x = x;
			image->player_pos.pos_y = y;
		}
	}
}

void	ft_rotate(int keysym, t_image *image)
{
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;

	dir_x = image->dir_pos.pos_x;
	dir_y = image->dir_pos.pos_y;
	plane_y = image->plane_pos.pos_y;
	plane_x = image->plane_pos.pos_x;
	if (keysym == XK_Right)
	{
		image->dir_pos.pos_x = dir_x * cos(ROT) - dir_y * sin(ROT);
		image->dir_pos.pos_y = dir_x * sin(ROT) + dir_y * cos(ROT);
		image->plane_pos.pos_x = plane_x * cos(ROT) - plane_y * sin(ROT);
		image->plane_pos.pos_y = plane_x * sin(ROT) + plane_y * cos(ROT);
	}
	else if (keysym == XK_Left)
	{
		image->dir_pos.pos_x = dir_x * cos(-ROT) - dir_y * sin(-ROT);
		image->dir_pos.pos_y = dir_x * sin(-ROT) + dir_y * cos(-ROT);
		image->plane_pos.pos_x = plane_x * cos(-ROT) - plane_y * sin(-ROT);
		image->plane_pos.pos_y = plane_x * sin(-ROT) + plane_y * cos(-ROT);
	}
}

int	key_press(int keysym, t_image *image)
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;

	x = image->player_pos.pos_x;
	y = image->player_pos.pos_y;
	dir_x = image->dir_pos.pos_x * SPEED;
	dir_y = image->dir_pos.pos_y * SPEED;
	if (keysym == XK_w)
		key_press1('w', image, y + dir_y, x + dir_x);
	if (keysym == XK_d)
		key_press1('d', image, y + dir_x, x - dir_y);
	if (keysym == XK_a)
		key_press1('a', image, y - dir_x, x + dir_y);
	if (keysym == XK_s)
		key_press1('s', image, y - dir_y, x - dir_x);
	ft_rotate(keysym, image);
	if (keysym == XK_Escape)
		ft_clean(image);
	print_background(image, image->map_game->map_game);
	return (0);
}

int	ft_mouse(int x, int y, t_image *image)
{
	(void)y;
	if (x < image->mouse.x)
		ft_rotate(XK_Left, image);
	else
		ft_rotate(XK_Right, image);
	mlx_mouse_get_pos(image->mlx, image->win, &image->mouse.x, &image->mouse.y);
	return (0);
}
