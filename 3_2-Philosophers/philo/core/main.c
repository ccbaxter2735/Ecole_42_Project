/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:48:33 by terussar          #+#    #+#             */
/*   Updated: 2023/10/02 10:52:37 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	initialize_arg(t_data *data, char **av, int ac)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_x_eat = ft_atoi(av[5]);
	else
		data->nb_x_eat = -1;
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (parsing(ac, av) == 0)
	{
		initialize_arg(&data, av, ac);
		init_forks(&data);
		init_philo(&data);
		if (initialize_thread(&data))
		{
			return (1);
		}
	}
	else
		ft_strerror("Error\nwrong number of arguments or non-unsigned integer\n");
	return (0);
}
