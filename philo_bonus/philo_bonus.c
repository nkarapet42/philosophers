/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:45:20 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/06 17:10:25 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	start_simulation(&philo);
	return (0);
}
