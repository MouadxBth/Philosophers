/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:58:02 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 23:29:52 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_check_eating(t_philosopher *philosopher)
{
	int		minimum_eating;

	minimum_eating = philosopher->info->minimum_eat_times;
	if (minimum_eating > 0
		&& philosopher->times_eaten >= minimum_eating)
	{
		pthread_mutex_lock(&philosopher->info->eating);
		philosopher->info->done_eating++;
		pthread_mutex_unlock(&philosopher->info->eating);
	}
}

void	*ft_begin_cycle(void *arg)
{
	t_philosopher	*philosopher;
	int				eating;

	philosopher = (t_philosopher *)arg;
	eating = philosopher->info->minimum_eat_times > 0;
	while (1)
	{
		pthread_mutex_lock(&philosopher->fork);
		ft_print_message(philosopher, "has taken a fork");
		pthread_mutex_lock(&philosopher->right->fork);
		ft_print_message(philosopher, "has taken a fork");
		ft_print_message(philosopher, "is eating");
		usleep(philosopher->info->time_to_eat * 1000);
		philosopher->last_time_eaten = ft_current_time();
		philosopher->times_eaten++;
		if (eating)
			ft_check_eating(philosopher);
		pthread_mutex_unlock(&philosopher->fork);
		pthread_mutex_unlock(&philosopher->right->fork);
		ft_print_message(philosopher, "is sleeping");
		usleep(philosopher->info->time_to_sleep * 1000);
		ft_print_message(philosopher, "is thinking");
	}
	return (NULL);
}
