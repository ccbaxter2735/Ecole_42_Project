/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:23:26 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 11:22:57 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	postpone_philo(t_philo *philo)
{
	if (philo->data->nb_philo == 1)
	{
		ft_usleep(philo, philo->data->time_to_die);
		take_time_and_str(philo, "is dead");
		return (1);
	}
	if ((philo->id % 2 == 0 && philo->data->nb_philo % 2 == 0)
		|| ((philo->id % 2 == 0 || philo->id == philo->data->nb_philo)
			&& philo->data->nb_philo % 2 == 1))
		ft_usleep(philo, 10);
	return (0);
}

void	*threading(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (postpone_philo(philo) != 0)
		return (NULL);
	while (is_dead(philo) == 0)
	{
		if (ft_eat(philo) != 0)
			break ;
		pthread_mutex_lock(&(philo->data->meal));
		if (philo->data->nb_philo_x_eat == philo->data->nb_philo)
		{
			pthread_mutex_unlock(&(philo->data->meal));
			take_time_and_str(philo, "is thinking");
			break ;
		}
		pthread_mutex_unlock(&(philo->data->meal));
		if (ft_sleep(philo) != 0)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}
