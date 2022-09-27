/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:50 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/27 01:13:45 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	ft_milliseconds(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (result);
}

void	ft_usleep(long time)
{
	long	start;

	start = ft_milliseconds();
	usleep(time * 920);
	while (ft_milliseconds() < start + time)
		usleep(time);
}

void	ft_print_message(t_philosopher *philosopher, char *str)
{
	long	timestamp;

	if (!philosopher || !str)
		return ;
	sem_wait(philosopher->info->printing);
	timestamp = ft_milliseconds() - philosopher->info->start;
	printf("%ld %i %s\n", timestamp, philosopher->id, str);
	sem_post(philosopher->info->printing);
}

sem_t	*ft_new_semaphore(char *name, int value)
{
	sem_t	*result;

	if (!name || value < 0)
		return (NULL);
	result = sem_open(name, O_CREAT | O_EXCL, 644, value);
	if (result == SEM_FAILED)
	{
		sem_unlink(name);
		return (sem_open(name, O_CREAT | O_EXCL, 644, value));
	}
	return (result);
}
