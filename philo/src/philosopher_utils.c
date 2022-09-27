/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:50 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/26 22:26:16 by mbouthai         ###   ########.fr       */
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
		usleep(time);
}

void	ft_print_message(t_philosopher *philosopher, char *str)
{
	pthread_mutex_lock(&philosopher->info->printing);
	printf("%lld %i %s\n", ft_milliseconds() - philosopher->info->start, philosopher->id, str);
	pthread_mutex_unlock(&philosopher->info->printing);
}
