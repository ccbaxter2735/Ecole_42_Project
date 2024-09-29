/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:50:34 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 11:28:27 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	ft_usleep(t_philo *philo, long time)
{
	long	time2;

	if (is_dead(philo) != 0)
		return (1);
	time2 = ft_time();
	while ((ft_time() - time2) < time)
	{
		if (is_dead(philo) != 0)
			return (1);
		usleep(10);
	}
	return (0);
}

long	ft_time(void)
{
	struct timeval		current_time;
	long				time_ms;

	if (gettimeofday(&current_time, NULL) == -1)
	{
		ft_strerror("error\ngettimeofday returned -1\n");
		return (-1);
	}
	time_ms = (current_time.tv_usec / 1000) + (current_time.tv_sec * 1000);
	return (time_ms);
}

void	take_time_and_str(t_philo *philo, char *str)
{
	long	time;

	time = -1;
	time = ft_time() - philo->start_time;
	if (time >= 0 && philo->data->end_b == 0)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%ld %d %s\n", time, philo->id, str);
		pthread_mutex_unlock(&philo->data->write);
	}
}
