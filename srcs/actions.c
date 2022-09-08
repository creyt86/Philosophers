/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:00:35 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 12:39:41 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	takes_forks(t_philo *philo)
{
	int			i;
	long int	time;

	time = philo->args->end_time;
	i = philo->name - 1;
	pthread_mutex_lock(&philo->fork);
	print(YELLOW, philo, M_FORK);
	if (philo->args->nbr_of_philo - 1 == philo->name - 1)
		pthread_mutex_lock(&philo->args->philos[0].fork);
	else
		pthread_mutex_lock(&philo->args->philos[i + 1].fork);
	print(YELLOW, philo, M_FORK);
	if (philo->args->nbr_of_meal == 0)
		error_exit(WHITE"Sorry, no meals to eat today...");
}

void	ft_eat(t_philo *philo)
{
	int	i;

	i = philo->name -1;
	print(GREEN, philo, M_EAT);
	usleep(philo->args->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->fork);
	if (philo->args->nbr_of_philo - 1 == philo->name - 1)
		pthread_mutex_unlock(&philo->args->philos[0].fork);
	else
		pthread_mutex_unlock(&philo->args->philos[i + 1].fork);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->args->nbr_of_meal)
		philo->args->all_meal_eaten++;
	if (philo->args->nbr_of_meal != 0
		&& philo->args->all_meal_eaten == philo->args->nbr_of_philo)
		error_exit(WHITE"All meals has been eaten by all philos 🍝");
	philo->last_meal = timestamp();
}

void	ft_think(t_philo *philo)
{
	print(PURP, philo, M_THINK);
}

void	ft_sleep(t_philo *philo)
{
	print(BLUE, philo, M_SLEEP);
	usleep(philo->args->time_to_sleep * 1000);
}

void	ft_dead(t_philo *philo, t_args *args)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (philo[i].alive)
	{
		// printf("lastmeal[%d] name[%d]\n", philo[i].last_meal, philo[i].name);
		if (philo[i].last_meal + philo->args->time_to_die < timestamp())
		{
			j = i;
			i = -1;
			while (++i < philo->args->nbr_of_philo)
			{
				philo[i].alive = false;
			}
			break ;
		}
		i++;
		if (i >= philo->args->nbr_of_philo)
			i = 0;
	}
	pthread_mutex_lock(&args->mutex);
	printf(RED"%s%ld |%s%d | %s", M_TIME, timestamp(), M_PHILO, philo[j].name, M_DIE);
	pthread_mutex_unlock(&args->mutex);
	// int	check_philos(t_philo *philo);
	// int	check_philos_2(t_philo *philo);
	// if ((timestamp()) >= (philo->args->time_to_die))
	// 	philo->alive = false;
	// i = -1;
	// while (++i < philo->args->nbr_of_philo)
	// {
	// 	philo[i].alive = false;
	// }
	usleep(1500);
	free_ture(philo);
	exit_thread(philo, args);
}
