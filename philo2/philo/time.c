/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukurekc <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:06:58 by bukurekc          #+#    #+#             */
/*   Updated: 2023/07/17 12:06:59 by bukurekc         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/time.h>

uint64_t	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

uint64_t	time_from_start(t_table *table)
{
	return (current_time() - table->time);
}

void	time_usleep(uint16_t micsec)
{
	uint64_t	current;

	current = current_time();
	while (1)
	{
		if (current_time() - current >= micsec)
			break ;
		usleep(100);
	}
}
