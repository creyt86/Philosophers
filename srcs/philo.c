/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:50:49 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/08 15:01:16 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_args		args;
	t_philo		*philos;

	check_errors(argc, argv);
	printf("erreurs check\n");
	argv_to_int(argc, argv, &args);
	philos = ft_present(&args);
	printf("j'ai fait argv\n");
	find_my_forks(philos, &args);
	free_ture(philos);
	return (0);
}
