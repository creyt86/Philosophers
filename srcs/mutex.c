/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:23:22 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 12:36:22 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// int	ft_init_mutex(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (++i < philo->args->nbr_of_philo)
// 	{
// 		if (pthread_mutex_init(philo[i].left_fork, NULL))
// 			return (1);
// 		if (pthread_mutex_init(philo[i].right_fork, NULL))
// 			return (1);
// 	}
// 	if (pthread_mutex_init(&philo->args->mutex, NULL))
// 		return (1);
// 	return (0);
// }

void	ft_init_mutex(t_philo *philo)
{
	pthread_mutex_init(&philo->args->mutex, NULL);
	pthread_mutex_init(&philo->fork, NULL);
	//pthread_mutex_init(philo->right_fork, NULL);
}

void	ft_destroy_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	while (++i < philos->args->nbr_of_philo)
	{
		pthread_mutex_destroy(&philos[i].fork);
	//	pthread_mutex_destroy(philos[i].right_fork);
	}
}

void	exit_mutex(t_philo *philo, t_args *args)
{
	int	i;

	// i = -1;
	// while (++i < args->nbr_of_philo)
	// 	pthread_join(philo[i].th_philo, NULL);
	i = -1;
	while (++i < args->nbr_of_philo)
		ft_destroy_mutex(philo);
	pthread_mutex_destroy(&philo->args->mutex);
}

void	exit_thread(t_philo *philo, t_args *args)
{
	int	i;

	// i = -1;
	// while (++i < args->nbr_of_philo)
	// 	pthread_join(philo[i].th_philo, NULL);
	i = -1;
	while (++i < args->nbr_of_philo)
		ft_destroy_mutex(philo);
	pthread_mutex_destroy(&(args->mutex));
	//pthread_mutex_destroy(&(args->eat));
}
