/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_death_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:36 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/17 01:24:06 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	ft_check_eating(t_info *info)
{
	if (info->minimum_eat_times > 0
		&& info->done_eating >= info->number_of_philosophers)
	{
		sem_wait(info->printing);
		sem_post(info->exit);
		return (1);
	}
	return (0);
}

static int	ft_check_time(t_philosopher *index, long time)
{
	if (time - index->last_time_eaten >= index->info->time_to_die)
	{
		index->is_dead = 1;
		ft_print_message(index, "died");
		sem_wait(index->info->printing);
		sem_post(index->info->exit);
		return (1);
	}
	return (0);
}

void	*ft_check_for_death(void *arg)
{
	t_philosopher	*index;
	t_info			*info;
	long			time;

	index = (t_philosopher *)arg;
	info = index->info;
	while (1)
	{
		if (ft_check_eating(info))
			return (NULL);
		time = ft_current_time();
		if (ft_check_time(index, time))
			return (NULL);
	}
	return (NULL);
}
