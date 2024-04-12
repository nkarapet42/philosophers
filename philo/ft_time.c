/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:55:32 by nkarapet          #+#    #+#             */
/*   Updated: 2024/04/05 16:39:32 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	static long long	start;
	struct timeval		t1;

	if (start == 0)
	{
		gettimeofday(&t1, NULL);
		start = (t1.tv_sec * 1000 + t1.tv_usec / 1000);
	}
	gettimeofday(&t1, NULL);
	return ((t1.tv_sec * 1000) + (t1.tv_usec / 1000) - start);
}

void	m_sleep(long long time)
{
	long long	t2;

	t2 = get_time();
	while (get_time() - t2 <= time)
		usleep(500);
}
