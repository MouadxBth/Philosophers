/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:58:02 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/27 01:09:42 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_think(t_philosopher *philosopher)
{
	ft_print_message(philosopher, "is thinking");
}

static void	ft_sleep(t_philosopher *philosopher)
{
	ft_print_message(philosopher, "is sleeping");
	ft_usleep(philosopher->info->time_to_sleep);
}

static void	ft_eat(t_philosopher *philosopher)
{
	ft_print_message(philosopher, "is eating");
	ft_usleep(philosopher->info->time_to_eat);
	philosopher->last_time_eaten = ft_milliseconds();
	philosopher->times_eaten++;
	if (!philosopher->is_done
		&& philosopher->info->minimum_eat_times > 0
		&& philosopher->times_eaten
		>= philosopher->info->minimum_eat_times)
	{
		philosopher->info->done_eating++;
		philosopher->is_done = 1;
	}
	pthread_mutex_unlock(&philosopher->fork);
	pthread_mutex_unlock(&philosopher->right->fork);
}

static void	ft_pickup_forks(t_philosopher *index)
{
	pthread_mutex_lock(&index->fork);
	pthread_mutex_lock(&index->right->fork);
	ft_print_message(index, "has taken a fork");
	ft_print_message(index, "has taken a fork");
}

void	*ft_begin_cycle(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	if (philosopher->id % 2 == 0)
		ft_usleep(philosopher->info->time_to_eat);
	while (!philosopher->is_dead && !philosopher->info->exit)
	{
		if (!philosopher->info->exit && !philosopher->is_dead)
			ft_pickup_forks(philosopher);
		if (!philosopher->info->exit && !philosopher->is_dead)
			ft_eat(philosopher);
		if (!philosopher->info->exit && !philosopher->is_dead)
			ft_sleep(philosopher);
		if (!philosopher->info->exit && !philosopher->is_dead)
			ft_think(philosopher);
	}
	return (NULL);
}
