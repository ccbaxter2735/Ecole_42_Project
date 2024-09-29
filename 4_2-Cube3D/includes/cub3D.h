/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:38 by khle              #+#    #+#             */
/*   Updated: 2024/01/19 16:51:44 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define BUFFER_SIZE 42
# define SCRHGHT 720
# define SCRWDTH 1420
# define FOV 0.66
# define PI 3.1415926535
# define DR 0.0174533
# define SPEED 0.15
# define ROT 0.05

typedef struct s_map
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			player_x;
	int			player_y;
	char		player_dir;
	int			floor;
	int			ceiling;
	char		**map_game;
}		t_map;

typedef struct s_size
{
	int			height;
	int			width;
}			t_size;

typedef struct s_texture
{
	t_size		size;
	char		*path;
	void		*content;
	int			*addr;
}			t_texture;

typedef struct s_pos
{
	double			pos_x;
	double			pos_y;
}			t_pos;

typedef struct s_pos_int
{
	int			x;
	int			y;
}			t_pos_int;

typedef struct s_line
{
	t_pos_int	ori;
	t_pos_int	p1;
	t_pos_int	p2;
}			t_line;

typedef struct s_image
{
	t_map		*map_game;
	void		*mlx;
	t_size		size;
	t_texture	*north;
	t_texture	*west;
	t_texture	*south;
	t_texture	*east;
	t_texture	*screen_txt;

	void		*img_black;
	void		*img_white;
	int			img_height;
	int			img_width;
	int			height;
	int			width;
	t_pos		player_pos;
	t_pos		dir_pos;
	t_pos		plane_pos;
	double		pa;
	int			speed;
	void		*win;
	int			hit;
	int			side;
	t_pos_int	map;
	t_pos_int	step;
	double		camera_x;
	t_pos		ray_dir;
	t_pos		delta_dist;
	t_pos		size_dist;
	double		wall_dist;
	int			line_hight;
	int			draw_start;
	int			draw_end;
	int			keysym;
	t_pos_int	mouse;
}		t_image;

////////////////////////////////Parsing/////////////////////////////////////

//check_map.c

int			check_name_image(t_map *map);
int			ft_check_image(char **map, t_map *map_game);
int			ft_color_cf(char *str);
int			ft_check_color(char **map, t_map *map_game);
int			ft_check_charac(char *str, int *count, t_map *map_game);

//parsing.c

void		ft_check_map_border(char **map, int y, int x, int *exit);
int			copy_map(char ***map, int start, int len);
char		**ft_final_map(char **map, t_map *map_game);
char		**ft_parsing(char *av1, t_map *map_game);
int			check_map_name(char *av1);

//utils_parsing.c

char		*open_map_file(int fd);
int			ft_find1(char *str, char *to_find);
int			ft_find2(char **str, char *tofind, int *pos);
char		*ft_link_image(char *str);
int			check_line(char **map);

////////////////////////////////utils/////////////////////////////////////

//ft_itoa.c
int			ft_get_neg(int n);
int			ft_get_len(int n);
char		*ft_itoa2(long long n);
int			ft_free_tab(char **str);
char		*copy_new(char *str, int *i);

//ft_split.c

char		**ft_split2(char *s, char c);
int			check_name_image1(t_map *map_game);

//libft.c
void		*ft_memset2(void *b, int c, size_t len);
int			ft_atoi2(char *str, int *pos);
char		*ft_strjoin2(char *s1, char *s2);
char		*ft_strdup2(char *str1);
int			check_open_image(char *image);

////////////////////////////////init_mlx/////////////////////////////////////

t_texture	*set_texture(t_image *image, char *wall_image);
int			init_wall_image(t_map *map_game, t_image *image);
int			init_mlx(t_map *map_game, t_image *image);
void		ft_clean(t_image *image);
void		clean_image(t_image *image, t_texture *txt);

////////////////////////////////raycast/////////////////////////////////////

//fond_color.c

int			init_floor_ceilling(t_image *image);
void		fill_floor_ceiling(t_image *image);
//int			get_color(t_image *image, t_texture *wall, int *i);
int			get_color(t_image *image, t_texture *wall, int start);

//utils_cast.c

void		init_element(t_image *image, int x);
void		calculate_side_dist(t_image *image);
void		ft_dda(t_image *image);
void		calculate_wall_dist(t_image *image);
void		fill_image(t_image *image, int x);

///////////////////////////////minimap/////////////////////////////////////
void		print_img(t_image *image, void *img, int x, int y);
void		set_img_background(t_image *image);
void		make_square(t_image *image, int x, int y, int color);
void		print_background(t_image *image, char **map);
void		draw_line(t_image *data, t_line *line, int color);
int			get_h(t_image *image);
int			get_w(t_image *image, int j);

//raycast.c

int			raycast(void *para);

//key.c
int			key_press(int keysym, t_image *image);
int			ft_mouse(int x, int y, t_image *image);

//clear.c
int			end(t_image *image);

////////////////////////////////cub3D/////////////////////////////////////

void		init_map_game(t_map *map_game);
void		ft_free_map(t_map *map_game);

#endif
