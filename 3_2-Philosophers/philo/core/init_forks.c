/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:26:23 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 10:27:33 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	free_fork(pthread_mutex_t *forks, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		pthread_mutex_destroy(&forks[j]);
		j++;
	}
	free(forks);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free_fork(data->forks, i);
			return (1);
		}
		i++;
	}
	return (0);
}
