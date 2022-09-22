/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:50 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/22 08:05:53 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	u_current_time(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1e6 + time.tv_usec;
	return (result);
}

void	ft_usleep(long time)
{
	long	start;

	start = u_current_time();
	while (u_current_time() - start <= time)
		usleep(30);
}

long	ft_current_time(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (result);
}

void	ft_print_message(t_philosopher *philosopher, char *str)
{
	long	timestamp;

	if (!philosopher || !str)
		return ;
	timestamp = ft_current_time() - philosopher->info->start;
	pthread_mutex_lock(&philosopher->info->printing);
	printf("%ld %i %s\n", timestamp, philosopher->id, str);
	pthread_mutex_unlock(&philosopher->info->printing);
}
