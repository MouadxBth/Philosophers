/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:51:37 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/17 01:04:44 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	ft_check_eating(t_philosopher *philosopher)
{
	int		minimum_eating;

	minimum_eating = philosopher->info->minimum_eat_times;
	if (minimum_eating <= 0)
		return ;
	if (philosopher->times_eaten >= minimum_eating)
	{
		sem_wait(philosopher->info->eating);
		philosopher->info->done_eating++;
		sem_post(philosopher->info->eating);
	}
}

void	ft_begin_cycle(t_philosopher *philosopher)
{
	pthread_t		death;

	pthread_create(&death, NULL, ft_check_for_death, philosopher);
	while (!philosopher->is_dead)
	{
		sem_wait(philosopher->info->forks);
		ft_print_message(philosopher, "has taken a fork");
		sem_wait(philosopher->info->forks);
		ft_print_message(philosopher, "has taken a fork");
		ft_print_message(philosopher, "is eating");
		usleep(philosopher->info->time_to_eat * 1000);
		philosopher->last_time_eaten = ft_current_time();
		philosopher->times_eaten++;
		ft_check_eating(philosopher);
		sem_post(philosopher->info->forks);
		sem_post(philosopher->info->forks);
		ft_print_message(philosopher, "is sleeping");
		usleep(philosopher->info->time_to_sleep * 1000);
		ft_print_message(philosopher, "is thinking");
	}
	pthread_detach(death);
	exit(0);
}
