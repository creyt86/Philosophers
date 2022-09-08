/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:39:29 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/01 11:14:25 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_ture(t_philo *philo)
{
	//if (philo->left_fork)
	//	free(philo->left_fork);
	//if (philo->right_fork)
	//	free(philo->right_fork);
	free(philo);
	exit(0);
}