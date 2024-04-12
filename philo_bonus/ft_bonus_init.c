/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:47:31 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/09 14:45:12 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	open_sem(t_philo *philo)
{
	philo->each_eat_sem = sem_open(EAT_SEM, O_CREAT, 0777, 1);
	philo->last_eat_time_sem = sem_open(LAST_EAT_SEM, O_CREAT, 0777, 1);
	philo->forks = sem_open(FORKS_SEM, O_CREAT, 0777, philo->num_of_philo);
	philo->print_sem = sem_open(PRINT_SEM, O_CREAT, 0777, 1);
	philo->die_sem = sem_open(DIE_SEM, O_CREAT, 0777, 1);
	if (philo->each_eat_sem == SEM_FAILED || philo->die_sem == SEM_FAILED
		|| philo->forks == SEM_FAILED || philo->print_sem == SEM_FAILED
		|| philo->last_eat_time_sem == SEM_FAILED)
		return (1);
	return (0);
}

void	arg_init(int argc, char **argv, t_philo *philo)
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->die_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	philo->die = 0;
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
	philo->philos = malloc(sizeof(t_tread) * philo->num_of_philo);
	if (!philo->philos)
		return (1);
	argc = -1;
	while (++argc < philo->num_of_philo)
	{
		philo->philos[argc].last_eat_time = LLONG_MAX;
		philo->philos[argc].id = argc;
		philo->philos[argc].each_eat = 0;
		philo->philos[argc].die = &philo->die;
		philo->philos[argc].philo = philo;
	}
	close_and_unlink(philo);
	if (open_sem(philo) == 1)
	{
		free(philo->philos);
		return (1);
	}
	return (0);
}
