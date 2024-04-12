/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:25:47 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/04 17:17:33 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_emulation(t_philo *philo)
{
	int	i;

	i = -1;
	get_time();
	while (++i < philo->num_of_philo)
		pthread_create(&philo->philos[i].tid, NULL,
			(void *)ft_simulation, philo->philos + i);
	while (1)
	{
		if (check_die(philo) == 1 || check_eat(philo) == 1)
			break ;
	}
	i = -1;
	while (++i < philo->num_of_philo)
	{
		pthread_join(philo->philos[i].tid, NULL);
		pthread_mutex_destroy(&philo->forks[i]);
		pthread_mutex_destroy(&philo->philos[i].each_eat_mutex);
		pthread_mutex_destroy(&philo->philos[i].last_eat_time_mutex);
	}
	free(philo->forks);
	free(philo->philos);
	pthread_mutex_destroy(&philo->print_mutex);
	pthread_mutex_destroy(&philo->die_mutex);
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	philo;

	i = -1;
	if (argc == 5 || argc == 6)
	{
		if (philo_init(argc, argv, &philo) == 1)
			return (1);
	}
	else
		return (1
			&& printf("INVALID NUMBER OF ARGUMENTS -> %d : Need 4 or 5\n",
				argc - 1));
	start_emulation(&philo);
	return (0);
}
