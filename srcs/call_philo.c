/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:36:15 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 09:12:07 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print(char *str, t_philo *philo, char *str2)
{
	pthread_mutex_lock(&(philo->args->mutex));
	if (philo->alive == true)
	{
		printf("%sTimestamp(ms): %ld |philo n°%d %s", str, timestamp(),
			philo->name, str2);
	}
	pthread_mutex_unlock(&(philo->args->mutex));
}

void	print_die(char *str, t_philo *philo, long int time, char *str2)
{
	pthread_mutex_lock(&(philo->args->mutex));
	if (philo->alive == true)
	{
		printf("%sTimestamp(ms): %ld |philo n°%d %s", str, time,
			philo->name, str2);
	}
	pthread_mutex_unlock(&(philo->args->mutex));
}

t_philo	*ft_present( t_args *args)
{
	long int	p;
	t_philo		*philos;

	philos = malloc(sizeof(t_philo) * (args->nbr_of_philo));
	if (!philos)
		return (0);
	p = 0;
	philos->nbr_of_fork = args->nbr_of_philo;
	args->start_time = 0;
	args->end_time = 0;
	args->all_meal_eaten = 0;
	philos->last_meal = 0;
	while (p < args->nbr_of_philo)
	{
		philos[p].name = p + 1;
		philos[p].meals_eaten = 0;
		philos[p].alive = true;
		//philos[p].last_meal = 0;
		philos[p].args = args;
		philos[p].args->end_time = 0;
		p++;
	}
	return (philos);
}

int	find_my_forks(t_philo *philos, t_args *args)
{
	long int	i;

	i = 0;
	while (i < args->nbr_of_philo)
	{
		//&philos[i].fork = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(&philos[i].fork, NULL) != 0)
			return (1);
		i++;
	}
	if (args->nbr_of_philo == 1)
	{
		//philo[i].right_fork = philo[i].left_fork;
		usleep(args->time_to_die * 1000);
		ft_dead(philos, args);
	}
	else
		//lets_eat(philos);
		philo_thread(philos, args);
	return (0);
}

	// i = 0;
	// while (i < args->nbr_of_philo)
	// {
	// 	if (i == 0)
	// 	{
	// 		if (args->nbr_of_philo == 1)
	// 		{
	// 			philo[i].right_fork = philo[i].left_fork;
	// 			usleep(args->time_to_die * 1000);
	// 			ft_dead(&philo);
	// 		}
	// 		else
	// 			lets_eat(philo);
	// 	}
	// 	else
	// 		lets_eat(philo);
	// }
	// return (0);

void	ft_quincunx(t_philo *philos)
{
	long int	p;

	p = 1;
	if (philos[p].name % 2)
		usleep(philos->args->time_to_eat * 1000);
}

// void	ft_quincunx(t_philo *philo)
// {
// 	t_args	args;

// 	if (philo->name % 2)
// 	{
// 		usleep(philo->args->time_to_eat * 1000);
// 		find_my_forks(philo, &args);
// 	}
// 	else
// 		find_my_forks(philo, &args);
// }
