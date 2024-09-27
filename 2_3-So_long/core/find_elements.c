/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:34:42 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 16:34:18 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player(t_data *data)
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
			{
				data->pos.x = i;
				data->pos.y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	find_ennemy(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] != '\0' && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == 'A')
			{
				data->pos_e.x = i;
				data->pos_e.y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}
