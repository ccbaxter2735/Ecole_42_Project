/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:06:40 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 10:07:48 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct frame_s
{
	void	*img1;
	void	*img2;
	void	*img3;
}				t_frame;

typedef struct img_s
{
	void	*img_floor;
	t_frame	img_playerb;
	t_frame	img_playerh;
	t_frame	img_playerd;
	t_frame	img_playerg;
	t_frame	img_ennemy;
	void	*img_exit;
	void	*img_wallint;
	void	*img_wallg;
	void	*img_walld;
	void	*img_wallh;
	void	*img_wallbas;
	void	*img_wallchd;
	void	*img_wallchg;
	void	*img_wallcbd;
	void	*img_wallcbg;
	void	*img_collect;
	t_frame	*img_pla;
	t_frame	*img_pla_ennemy;
	void	*img_p_n;
	void	*img_ennemy_now;
	void	*win_windows;
	void	*los_windows;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;
// a remplacer par des define

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	int		width_win;
	int		height_win;
	char	**map;
	void	**tab_img;
	int		nb_img;
	int		compt;
	int		playing;
	t_cnt	content;
	t_img	img;
	t_pos	pos_e;
	t_pos	pos;
	int		count;
}				t_data;

void	render_top(t_data *data);
void	render_left(t_data *data);
void	render_right(t_data *data);
void	render_down(t_data *data);
void	win_windows(t_data *data);
void	lose_windows(t_data *data);
void	render_top_ennemy(t_data *data);
void	render_left_ennemy(t_data *data);
void	render_right_ennemy(t_data *data);
void	render_down_ennemy(t_data *data);

void	print_background(t_data *data);
void	print_other(t_data *data);
int		render(t_data *data);
void	print_map(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);

void	*ft_error(char *str);
int		ft_abs(int nb);
void	stop_game(int keysym, t_data *data);
void	test_map(t_data *data);

void	set_content(t_cnt *content);
void	set_img_background(t_data *data);
void	set_img_player(t_data *data);
void	set_img_ennemy(t_data *data);

int		get_heigh_map(t_data *data, char *map);
char	**get_map(int fd, int line, t_data *data);
char	**map_init(char **str, t_data *data);
void	ft_free_map(t_data *data);
int		check_case(t_data *data);
int		contain_pec(t_data *data);
int		is_surrounded(t_data *data);
int		check_column(t_data *data, int column);
int		check_line(t_data *data, int line);
int		is_rectangle(t_data *data);
void	flood_fill(char **map, int x, int y);
int		check_flood(t_data *data);
int		check_collectible(t_data *data);
void	recover_map(t_data *data);

int		end(t_data *data);
int		chk_collect(t_data *data);
int		key_press(int keysym, t_data *data);

void	find_player(t_data *data);
void	find_ennemy(t_data *data);
void	move_ennemy(t_data *data);

#endif