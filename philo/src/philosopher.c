/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:51:55 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 23:42:07 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_pickup_forks(t_philosopher *index)
{
	pthread_mutex_lock(&index->fork);
	pthread_mutex_lock(&index->right->fork);
	ft_print_message(index, "has taken a fork");
	ft_print_message(index, "has taken a fork");
}

static int	ft_eat(t_philosopher *index)
{
	ft_print_message(index, "is eating");
	ft_last_time_ate(index, ft_milliseconds());
	ft_msleep(index->info->time_to_sleep);
	pthread_mutex_unlock(&index->fork);
	pthread_mutex_unlock(&index->right->fork);
	return (ft_times_ate(index, -2));
}

static void	ft_sleep(t_philosopher *index)
{
	ft_print_message(index, "is sleeping");
	ft_msleep(index->info->time_to_sleep);
}

static void	ft_think(t_philosopher *index)
{
	ft_print_message(index, "is thinking");
}

void	*ft_begin_cycle(void *arg)
{
	t_philosopher	*index;

	index = (t_philosopher *)arg;
	if (!(index->id % 2))
		ft_msleep(5);
	while (ft_should_exit(index->info, -1) != 1)
	{
		ft_pickup_forks(index);
		if (ft_eat(index) == index->info->minimum_eat_times)
			return (NULL);
		ft_sleep(index);
		ft_think(index);
	}
	return (NULL);
}
