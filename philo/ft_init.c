/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:10:14 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/07 14:01:45 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	arg_init(int argc, char **argv, t_philo *philo)
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->die_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	philo->die = 0;
	pthread_mutex_init(&philo->die_mutex, NULL);
	pthread_mutex_init(&philo->print_mutex, NULL);
	if (argc == 6)
		philo->eat_number = ft_atoi(argv[5]);
	else
		philo->eat_number = -1;
}

int	check_inputs(int argc, char **argv, t_philo *philo)
{
	arg_init(argc, argv, philo);
	if (philo->num_of_philo <= 0 || philo->num_of_philo > 200)
		return (1);
	if (philo->die_time < 0)
		return (1);
	if (philo->eat_time < 0)
		return (1);
	if (philo->sleep_time < 0)
		return (1);
	if (argc == 6)
	{
		if (philo->eat_number < 0)
			return (1);
	}
	return (0);
}

int	philo_init(int argc, char **argv, t_philo *philo)
{
	if (check_inputs(argc, argv, philo) == 1)
		return (1 && printf("GIVEN ARGUMENTS INVALID\n"));
	argc = -1;
	philo->philos = malloc(sizeof(t_tread) * philo->num_of_philo);
	if (!philo->philos)
		return (1);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
	if (!philo->forks)
	{
		free(philo->philos);
		return (1);
	}
	while (++argc < philo->num_of_philo)
	{
		philo->philos[argc].id = argc;
		pthread_mutex_init(&philo->forks[argc], NULL);
		pthread_mutex_init(&philo->philos[argc].each_eat_mutex, NULL);
		pthread_mutex_init(&philo->philos[argc].last_eat_time_mutex, NULL);
		philo->philos[argc].last_eat_time = LLONG_MAX;
		philo->philos[argc].each_eat = 0;
		philo->philos[argc].die = &philo->die;
		philo->philos[argc].philo = philo;
	}
	return (0);
}
