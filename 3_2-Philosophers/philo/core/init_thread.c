/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:52:12 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 11:02:48 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	ft_thread_create(t_data *data)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = ft_time();
	while (i < data->nb_philo)
	{
		data->philo[i].start_time = tmp;
		data->philo[i].last_time_eat = 0;
		if (pthread_create(&data->philo[i].th_id, NULL,
				threading, &data->philo[i]))
		{
			ft_strerror("error\nfailed to create thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_thread_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].th_id, NULL) != 0)
		{
			ft_strerror("error\nfailed to join thread\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	initialize_thread(t_data *data)
{
	int		i;

	pthread_mutex_init(&(data->write), NULL);
	pthread_mutex_init(&(data->meal), NULL);
	pthread_mutex_init(&(data->end), NULL);
	data->end_b = 0;
	data->nb_philo_x_eat = 0;
	if (ft_thread_create(data) != 0)
		return (1);
	if (ft_thread_join(data) != 0)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		data->philo[i].fork_l = NULL;
		data->philo[i].fork_r = NULL;
		i++;
	}
	free(data->forks);
	free(data->philo);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->end);
	return (0);
}
