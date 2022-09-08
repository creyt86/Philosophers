/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:23:22 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 15:19:20 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init_mutex(t_philo *philo)
{
	pthread_mutex_init(&philo->args->mutex, NULL);
	pthread_mutex_init(&philo->fork, NULL);
}

void	ft_destroy_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	while (++i < philos->args->nbr_of_philo)
	{
		pthread_mutex_destroy(&philos[i].fork);
	}
}

void	exit_mutex(t_philo *philo, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nbr_of_philo)
		ft_destroy_mutex(philo);
	pthread_mutex_destroy(&philo->args->mutex);
}

void	exit_thread(t_philo *philo, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nbr_of_philo)
		ft_destroy_mutex(philo);
	pthread_mutex_destroy(&(args->mutex));
}
