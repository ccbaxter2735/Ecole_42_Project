/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:04:30 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 10:16:13 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	is_dead(t_philo	*philo)
{
	long	diff_time;

	diff_time = ft_time() - philo->start_time;
	pthread_mutex_lock(&(philo->data->end));
	if (philo->data->end_b == 1)
	{
		pthread_mutex_unlock(&(philo->data->end));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->end));
	if ((diff_time - philo->last_time_eat) < philo->data->time_to_die)
		return (0);
	else
	{
		pthread_mutex_lock(&(philo->data->end));
		take_time_and_str(philo, "is dead");
		philo->data->end_b = 1;
		pthread_mutex_unlock(&(philo->data->end));
	}
	return (1);
}
