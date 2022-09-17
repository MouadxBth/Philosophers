/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:50 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/17 01:24:51 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	sem_wait(philosopher->info->printing);
	printf("%ld %i %s\n", timestamp, philosopher->id, str);
	sem_post(philosopher->info->printing);
}

sem_t	*ft_new_semaphore(char *name, int value)
{
	if (!name || value < 0)
		return (NULL);
	sem_unlink(name);
	return (sem_open(name, O_CREAT,
			1 << 8 | 1 << 7 | 1 << 5 | 1 << 2, value));
}
