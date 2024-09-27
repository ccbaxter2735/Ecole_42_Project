/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:51:21 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 13:36:04 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangle(t_data *data)
{
	int	i;
	int	len;

	if (data->map[0] == 0)
	{
		ft_error("Error\nMap is empty\n");
		return (-1);
	}
	i = 0;
	len = ft_strlen(data->map[i]);
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) != len)
		{
			ft_error("Error\nMap is too small or not a rectangle\n");
			return (-1);
		}
	}
	data->width = len;
	return (data->width);
}

int	check_line(t_data *data, int line)
{
	int	j;

	j = 0;
	while (data->map[line][j] != '\0' && data->map[line][j] != '\n')
	{
		if (data->map[line][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	check_column(t_data *data, int column)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (data->map[i][column] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	is_surrounded(t_data *data)
{
	if (check_line(data, 0) == -1 || check_line(data, data->height - 1) == -1
		|| check_column(data, 0) == -1
		|| check_column(data, data->width - 1) == -1)
	{
		ft_error("Error\nMap is not surrounded by wall\n");
		return (-1);
	}
	return (0);
}

int	contain_pec(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->content.count_e = 0;
	data->content.count_p = 0;
	data->content.count_c = 0;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (data->map[i][j] == 'E')
				data->content.count_e++;
			else if (data->map[i][j] == 'P')
				data->content.count_p++;
			else if (data->map[i][j] == 'C')
				data->content.count_c++;
		}
	}
	if (data->content.count_e == data->content.count_p == 1
		&& data->content.count_p > 0 && data->content.count_c > 0)
		return (0);
	ft_error("Error\nToo many or few collectible, exit or start position\n");
	return (-1);
}
