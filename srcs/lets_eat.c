/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:11:19 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 12:24:50 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//if (current time - last meal > time to die --> meurt)
	//if (philo->last_meal > philo->args->time_to_die)
	//	philo->alive = false;

// int	check_philos(t_philo *philo)
// {
// 	if (((philo->alive == false) || ((philo->args->time_to_eat + philo->args->time_to_sleep) < (philo->args->time_to_die))))
// 		//printf("ca marche\n");
// 		return (0);
// 	return (1);
//}

int	check_philos(t_philo *philo)
{
	// printf("last%d name%d\n",philo->last_meal, philo->name);
	if (philo->alive)
		return (0);
	return (1);
}

int	check_philos_2(t_philo *philo)
{
	if (((philo->args->time_to_eat + philo->args->time_to_sleep)
			< (philo->args->time_to_die)))
		return (0);
	return (1);
}

int	lets_eat(t_philo *philos)
{
//	usleep(1500);
	// philos->last_meal = get_current_time_ms();
	if (!check_philos(philos))
	{
		if (philos->name % 2)
			usleep(philos->args->time_to_eat * 1000 / 2);
	}
//	usleep(1500);
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
		// philos[i].last_meal = timestamp();
	}
	i = -1;
	while (++i < philos->args->nbr_of_philo && !check_philos_2(philos))
		pthread_join(philos[i].th_philo, NULL);
	ft_dead(philos, args);
	exit_thread(philos, args);
}
