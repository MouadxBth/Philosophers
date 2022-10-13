/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_death_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:14:54 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 22:41:24 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_check_for_death(void *arg)
{
	t_philosopher	*index;
	long			time;

	index = (t_philosopher *)arg;
	while (1)
	{
		time = ft_milliseconds();
		if (time - index->last_time_eaten
			>= index->info->time_to_die)
		{
			index->is_dead = 1;
			sem_wait(index->info->printing);
			printf("%ld %i has died\n", time - index->info->start, index->id);
			sem_post(index->info->exit);
			return (NULL);
		}
	}
	return (NULL);
}
