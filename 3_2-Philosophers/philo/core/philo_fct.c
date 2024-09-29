/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:50:52 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 11:28:16 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	pick_forks(t_philo *philo)
{
	if (philo->data->nb_philo % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_l);
		take_time_and_str(philo, "has take a fork");
		pthread_mutex_lock(philo->fork_r);
		take_time_and_str(philo, "has take a fork");
	}
	else
	{
		pthread_mutex_lock(philo->fork_r);
		take_time_and_str(philo, "has take a fork");
		pthread_mutex_lock(philo->fork_l);
		take_time_and_str(philo, "has take a fork");
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

int	ft_eat(t_philo *philo1)
{
	if (is_dead(philo1) == 0)
	{
		pick_forks(philo1);
		take_time_and_str(philo1, "is eating");
		if (ft_usleep(philo1, philo1->data->time_to_eat) != 0)
		{
			drop_forks(philo1);
			return (1);
		}
		philo1->last_time_eat = ft_time();
		drop_forks(philo1);
		if (philo1->nb_meal != -1)
		{
			philo1->nb_meal--;
			if (philo1->nb_meal == 0)
			{
				pthread_mutex_lock(&(philo1->data->meal));
				philo1->data->nb_philo_x_eat++;
				pthread_mutex_unlock(&(philo1->data->meal));
				take_time_and_str(philo1, "is thinking");
			}
		}
		return (0);
	}
	return (1);
}

int	ft_sleep(t_philo *philo1)
{
	if (is_dead(philo1) == 0)
	{
		take_time_and_str(philo1, "is sleeping");
		ft_usleep(philo1, philo1->data->time_to_sleep);
		return (0);
	}
	return (1);
}

int	ft_think(t_philo *philo1)
{
	int	time_think;

	if (philo1->data->time_to_eat >= philo1->data->time_to_sleep)
		time_think = (philo1->data->time_to_eat - philo1->data->time_to_sleep);
	else
		time_think = 0;
	if (is_dead(philo1) == 0)
	{
		take_time_and_str(philo1, "is thinking");
		ft_usleep(philo1, time_think);
		return (0);
	}
	return (1);
}
