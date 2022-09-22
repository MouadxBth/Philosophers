/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:58:02 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/22 08:36:35 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_think(t_philosopher *philosopher)
{
	ft_print_message(philosopher, "is thinking");
}

static void	ft_sleep(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->fork);
	pthread_mutex_unlock(&philosopher->right->fork);
	ft_print_message(philosopher, "is sleeping");
	ft_usleep(1000*philosopher->info->time_to_sleep);
}

static void	ft_eat(t_philosopher *philosopher)
{
	ft_print_message(philosopher, "is eating");
	ft_usleep(1000*philosopher->info->time_to_eat);
	philosopher->last_time_eaten = ft_current_time();
	philosopher->times_eaten++;
	if (!philosopher->is_done
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
	}
}

static void	ft_pickup_forks(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
	{
		pthread_mutex_lock(&philosopher->fork);
		ft_print_message(philosopher, "has taken a fork");
		pthread_mutex_lock(&philosopher->right->fork);
		ft_print_message(philosopher, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philosopher->right->fork);
		ft_print_message(philosopher, "has taken a fork");
		pthread_mutex_lock(&philosopher->fork);
		ft_print_message(philosopher, "has taken a fork");
	}
}

void	*ft_begin_cycle(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	while (!philosopher->is_dead)
	{
		ft_pickup_forks(philosopher);
		ft_eat(philosopher);
		ft_sleep(philosopher);
		ft_think(philosopher);
	}
	return (NULL);
}
