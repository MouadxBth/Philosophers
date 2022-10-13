/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:27:13 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 22:05:20 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_message(t_philosopher *index, char *msg)
{
	pthread_mutex_lock(&index->info->printing);
	if (!ft_should_exit(index->info, -1))
		printf("%ld %i %s\n", ft_milliseconds()
			- index->info->start, index->id, msg);
	pthread_mutex_unlock(&index->info->printing);
}

int	ft_should_exit(t_info *info, int n)
{
	int	result;

	pthread_mutex_lock(&info->exit_mutex);
	if (n >= 0)
		info->exit = n;
	result = info->exit;
	pthread_mutex_unlock(&info->exit_mutex);
	return (result);
}

int	ft_times_ate(t_philosopher *philosopher, int n)
{
	int	result;

	pthread_mutex_lock(&philosopher->times_ate_mutex);
	if (n >= 0)
		philosopher->times_ate = n;
	else if (n == -2)
		philosopher->times_ate++;
	result = philosopher->times_ate;
	pthread_mutex_unlock(&philosopher->times_ate_mutex);
	return (result);
}

int	ft_done_eating(t_philosopher *index)
{
	int	done;
	int	current;

	if (!index || index->info->minimum_eat_times <= 0)
		return (0);
	done = 0;
	current = index->info->number_of_philosophers;
	while (index && --current >= 0)
	{
		if (ft_times_ate(index, -1) >= index->info->minimum_eat_times)
			done++;
		index = index->right;
	}
	return (done);
}

long	ft_last_time_ate(t_philosopher *philosopher, long n)
{
	long	result;

	pthread_mutex_lock(&philosopher->last_time_ate_mutex);
	if (n >= 0)
		philosopher->last_time_ate = n;
	else if (n == -1 && n == philosopher->last_time_ate)
		philosopher->last_time_ate = ft_milliseconds();
	result = philosopher->last_time_ate;
	pthread_mutex_unlock(&philosopher->last_time_ate_mutex);
	return (result);
}
