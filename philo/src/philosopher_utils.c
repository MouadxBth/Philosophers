/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:50 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/25 02:24:05 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_milliseconds(void)
{
	struct timeval	time;
	long long		result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (result);
}

long long	ft_microseconds(void)
{
	struct timeval	time;
	long long		result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1e6 + time.tv_usec;
	return (result);
}

void	ft_usleep(long long time)
{
	long	start;

	start = ft_milliseconds();
	usleep(time * 920);
	while (ft_milliseconds() < start + time)
		usleep(time * 3);
}

void	ft_print_message(t_philosopher *philosopher, char *str)
{
	long	timestamp;

	if (!philosopher || !str)
		return ;
	timestamp = ft_milliseconds() - philosopher->info->start;
	pthread_mutex_lock(&philosopher->info->printing);
	printf("%ld %i %s\n", timestamp, philosopher->id, str);
	if (str[0] != 'd')
		pthread_mutex_unlock(&philosopher->info->printing);
}
