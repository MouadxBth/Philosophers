/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_cleanup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:22:37 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 22:09:54 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_await_philosophers(t_philosopher *index)
{
	t_info	*info;
	int		count;

	if (!index)
		return (0);
	info = index->info;
	count = -1;
	while (index && ++count < info->number_of_philosophers)
	{
		if (pthread_join(index->thread, NULL))
			return (0);
		index = index->right;
	}
	return (1);
}

int	ft_destroy_mutexes(t_philosopher *index)
{
	t_info			*info;
	int				count;

	if (!index)
		return (0);
	info = index->info;
	count = -1;
	if (pthread_mutex_destroy(&info->printing)
		|| pthread_mutex_destroy(&info->exit_mutex))
		return (0);
	while (index && ++count < info->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&index->fork)
			|| pthread_mutex_destroy(&index->last_time_ate_mutex)
			|| pthread_mutex_destroy(&index->times_ate_mutex))
			return (0);
		index = index->right;
	}
	return (1);
}

void	ft_free_philosophers(t_philosopher *index)
{
	t_info			*info;
	t_philosopher	*temp;
	int				count;

	if (!index)
		return ;
	info = index->info;
	count = -1;
	while (index && ++count < info->number_of_philosophers)
	{
		temp = index;
		index = index->right;
		if (temp)
			free(temp);
	}
}
