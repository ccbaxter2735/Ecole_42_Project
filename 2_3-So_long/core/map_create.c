/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:19:58 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 15:21:09 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_heigh_map(t_data *data, char *map)
{
	char	*str;
	int		fd;

	data->height = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		data->height++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (data->height);
}

char	**get_map(int fd, int line, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	data->map = malloc(sizeof(char *) * (line + 1));
	if (!data->map)
		return (NULL);
	while (i < line)
	{
		str = get_next_line(fd);
		data->map[i] = ft_strdup(str);
		free(str);
		i++;
	}
	data->map[line] = 0;
	return (data->map);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map[i]);
	free(data->map);
	data->map = NULL;
	return ;
}

char	**map_init(char **str, t_data *data)
{
	int	fd;
	int	nb;

	if (ft_strncmp(str[1], ".ber", ft_strlen(str[1])) == 0)
		return (ft_error("Error\nNo map's name before .ber\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd == -1)
			return (ft_error("Error\nMap's name does not exist\n"));
		nb = get_heigh_map(data, str[1]);
		data->map = get_map(fd, nb, data);
		find_player(data);
		close(fd);
		test_map(data);
	}
	return (data->map);
}

void	print_map(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width), (data->height * data->img.height),
			"So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	print_background(data);
	data->playing = 1;
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
}

// int	main()
// {
// 	int			fd;
// 	t_data		data;
// 	t_cnt		cnt;
// 	int			i;
// 	int			nb;
// 	int			c;

// 	i = 0;
// 	ft_bzero(&data, sizeof(data));
// 	fd = open("map.ber", O_RDONLY);
// 	nb = get_heigh_map(&data, "map.ber");
// 	data.map = get_map(fd, nb, &data);
// 	while (i < nb)
// 	{
// 		write(2, data.map[i], ft_strlen(data.map[i]));
// 		i++;
// 	}
// 	close(fd);
// 	write(2, "\n\n", 2);
// 	find_player(&data);
// 	ft_printf("x = %d y = %d\n", data.pos.x, data.pos.y);
// 	flood_fill(data.map, data.pos.x, data.pos.y);
// 	c = check_flood(&data);
// 	ft_printf("flood = %d\n\n", c);
// 	i = 0;
// 	while (i < nb)
// 	{
// 		write(2, data.map[i], ft_strlen(data.map[i]));
// 		i++;
// 	}
// 	is_surrounded(&data);
// 	set_content(&cnt);
// 	contain_PEC(&data, &cnt);
// 	check_case(&data);
// 	return (0);
// }