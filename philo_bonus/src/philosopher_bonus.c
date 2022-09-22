/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:51:37 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/20 16:00:40 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	ft_think(t_philosopher *philosopher)
{
	ft_print_message(philosopher, "is thinking");
}

static void	ft_sleep(t_philosopher *philosopher)
{
	sem_post(philosopher->info->forks);
	sem_post(philosopher->info->forks);
	ft_print_message(philosopher, "is sleeping");
	usleep(philosopher->info->time_to_sleep * 1000);
}

static void	ft_eat(t_philosopher *philosopher)
{
	ft_print_message(philosopher, "is eating");
	usleep(philosopher->info->time_to_eat * 1000);
	philosopher->last_time_eaten = ft_current_time();
	philosopher->times_eaten++;
	if (!philosopher->is_done
		&& philosopher->info->minimum_eat_times > 0
		&& philosopher->times_eaten
		>= philosopher->info->minimum_eat_times)
	{
		sem_wait(philosopher->info->eating);
		sem_wait(philosopher->info->printing);
		sem_post(philosopher->info->done);
		philosopher->is_done = 1;
	}
}

static void	ft_pickup_forks(t_philosopher *philosopher)
{
	sem_wait(philosopher->info->forks);
	ft_print_message(philosopher, "has taken a fork");
	sem_wait(philosopher->info->forks);
	ft_print_message(philosopher, "has taken a fork");
}

void	ft_begin_cycle(t_philosopher *philosopher)
{
	pthread_t		death;

	if (!(philosopher->id % 2))
		usleep(philosopher->info->time_to_eat * 1000);
	pthread_create(&death, NULL, ft_check_for_death, philosopher);
	while (!philosopher->is_dead)
	{
		ft_pickup_forks(philosopher);
		ft_eat(philosopher);
		ft_sleep(philosopher);
		ft_think(philosopher);
	}
	pthread_detach(death);
	exit(0);
}
