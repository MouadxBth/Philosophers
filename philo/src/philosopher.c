/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:58:02 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/25 03:25:47 by mbouthai         ###   ########.fr       */
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
	philosopher->is_eating = 1;
	ft_print_message(philosopher, "is eating");
	ft_usleep(philosopher->info->time_to_eat);
	philosopher->last_time_eaten = ft_milliseconds();
	philosopher->times_eaten++;
	pthread_mutex_unlock(&philosopher->fork);
	pthread_mutex_unlock(&philosopher->right->fork);
	philosopher->is_eating = 0;
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
	t_info			*info;
	pthread_t		death;

	philosopher = (t_philosopher *)arg;
	info = philosopher->info;
	pthread_create(&death, NULL, ft_check_for_death, philosopher);
	if (philosopher->id % 2 == 0)
		ft_usleep(philosopher->info->time_to_eat);
	while (!philosopher->is_dead && !philosopher->info->exit)
	{
		if (!info->exit && !philosopher->is_dead)
			ft_pickup_forks(philosopher);
		if (!info->exit && !philosopher->is_dead)
			ft_eat(philosopher);
		if (!info->exit && !philosopher->is_dead)
			ft_sleep(philosopher);
		if (!info->exit && !philosopher->is_dead)
			ft_think(philosopher);
	}
	return (NULL);
}
/*	if (!philosopher->is_done
		&& philosopher->info->minimum_eat_times > 0
		&& philosopher->times_eaten
		>= philosopher->info->minimum_eat_times)
	{
		pthread_mutex_lock(&philosopher->info->eating);
		philosopher->info->done_eating++;
		philosopher->is_done = 1;
		if (philosopher->info->done_eating
			>= philosopher->info->number_of_philosophers)
		{
			pthread_mutex_lock(&philosopher->info->printing);
			philosopher->info->exit = 1;
			return ;
		}
		pthread_mutex_unlock(&philosopher->info->eating);
	}*/
