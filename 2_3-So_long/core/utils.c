/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:55:35 by terussar          #+#    #+#             */
/*   Updated: 2023/04/25 10:14:39 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (NULL);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	stop_game(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
}

void	test_map(t_data *data)
{
	if (check_case(data) == -1 || is_rectangle(data) == -1
		|| is_surrounded(data) == -1 || contain_pec(data) == -1)
		ft_free_map(data);
	else
	{
		flood_fill(data->map, data->pos.x, data->pos.y);
		if (check_flood(data) == -1 || check_collectible(data) == -1)
			ft_free_map(data);
		else
			recover_map(data);
	}
}
