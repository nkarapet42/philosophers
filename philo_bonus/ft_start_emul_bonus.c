/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_emul_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:41:14 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/06 18:42:16 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	close_and_unlink(t_philo *philo)
{
	sem_close(philo->each_eat_sem);
	sem_close(philo->last_eat_time_sem);
	sem_close(philo->forks);
	sem_close(philo->print_sem);
	sem_close(philo->die_sem);
	sem_unlink(EAT_SEM);
	sem_unlink(LAST_EAT_SEM);
	sem_unlink(FORKS_SEM);
	sem_unlink(PRINT_SEM);
	sem_unlink(DIE_SEM);
}

void	got_eat_time(t_tread *philos)
{
	sem_wait(philos->philo->last_eat_time_sem);
	philos->last_eat_time = get_time();
	sem_post(philos->philo->last_eat_time_sem);
}

void	*check_function(t_tread *philos)
{
	while (1)
	{
		if (check_die(philos) == 1 || check_eat(philos) == 1)
			break ;
	}
	return (NULL);
}

void	ft_simulation(t_tread *philos)
{
	pthread_create(&philos->tid, NULL,
		(void *)check_function, philos);
	got_eat_time(philos);
	while (1)
	{
		sem_wait(philos->philo->forks);
		sem_print(philos, "has taken a fork\n");
		sem_wait(philos->philo->forks);
		sem_print(philos, "has taken a fork\n");
		sem_print(philos, "is eating\n");
		m_sleep(philos->philo->eat_time);
		sem_post(philos->philo->forks);
		sem_post(philos->philo->forks);
		sem_wait(philos->philo->each_eat_sem);
		philos->each_eat++;
		sem_post(philos->philo->each_eat_sem);
		sem_print(philos, "is sleeping\n");
		got_eat_time(philos);
		m_sleep(philos->philo->sleep_time);
		sem_print(philos, "is thinking\n");
	}
	pthread_join(philos->tid, NULL);
	exit (0);
}

int	start_simulation(t_philo *philo)
{
	int	i;
	int	exit;

	i = -1;
	while (++i < philo->num_of_philo)
	{
		philo->philos[i].pid = fork();
		if (philo->philos[i].pid == 0)
			ft_simulation(&philo->philos[i]);
	}
	i = -1;
	while (++i <= philo->num_of_philo)
	{
		waitpid(-1, &exit, 0);
		if (WEXITSTATUS(exit) > 0)
		{
			i = -1;
			while (++i < philo->num_of_philo)
				kill(philo->philos[i].pid, SIGKILL);
			break ;
		}
	}
	close_and_unlink(philo);
	free(philo->philos);
	return (0);
}
