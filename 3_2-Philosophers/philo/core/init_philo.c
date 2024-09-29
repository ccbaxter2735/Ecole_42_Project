/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:14:06 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 10:15:24 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philo)
	{
		free(data->philo);
		return (1);
	}
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_meal = data->nb_x_eat;
		data->philo[i].last_time_eat = ft_time();
		data->philo[i].fork_l = &data->forks[((i + 1) + ((i + 1) % 2))
			% data->nb_philo];
		data->philo[i].fork_r = &data->forks[((i + 1) + !((i + 1) % 2))
			% data->nb_philo];
		data->philo[i].data = data;
		i++;
	}
	return (0);
}
