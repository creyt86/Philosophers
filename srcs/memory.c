/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:39:29 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 16:32:27 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_ture(t_philo *philo)
{
	free(philo);
	exit(0);
}
/*
void	can_i_leave_the_table(t_philo *philo)
{
	int	i;
	int	p;

	p = philo->meals_eaten - 1;
	pthread_mutex_lock(&philo->args->mutex);
	printf(WHITE"All %d meals has been eaten by all philos 🍝\n",
		philo->args->all_meal_eaten);
	pthread_mutex_unlock(&philo->args->mutex);
	i = -1;
	while (++i < philo->args->nbr_of_philo)
	{
		philo[p].alive = false;
	}
	usleep(1500);
	free_ture(philo);
	exit_thread(philo, philo->args);
}
Ca ne marche malheureusemet pas. Le philo 1 meure et il y a quand meme du
texte qui s'affiche dessous. Peut etre a cause du check philos ?
*/
