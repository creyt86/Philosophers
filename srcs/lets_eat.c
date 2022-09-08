/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:11:19 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 16:36:55 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_philos(t_philo *philo)
{
	if (philo->alive
		&& philo->last_meal + philo->args->time_to_die > timestamp())
		return (0);
	philo->alive = false;
	return (1);
}

int	lets_eat(t_philo *philos)
{
	if (!check_philos(philos))
	{
		if (philos->name % 2)
			ft_usleep(philos->args->time_to_eat);
	}
	while (!check_philos(philos))
	{
		if (!check_philos(philos))
			takes_forks(philos);
		if (!check_philos(philos))
			ft_eat(philos);
		if (!check_philos(philos))
			ft_sleep(philos);
		if (!check_philos(philos))
			ft_think(philos);
	}
	return (1);
}

void	philo_thread(t_philo *philos, t_args *args)
{
	int	i;

	i = -1;
	ft_start(args);
	while (++i < args->nbr_of_philo)
	{
		philos[i].args->philos = philos;
		philos[i].last_meal = timestamp();
		if (pthread_create(&(philos[i].th_philo), NULL,
				(void *)lets_eat, &(philos[i])))
		{
			free_ture(philos);
			error_exit("error : bad arguments");
		}
	}
	ft_dead(philos, args);
	exit_thread(philos, args);
}
