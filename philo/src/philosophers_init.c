/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:03:05 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 17:49:25 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_initialize_info(t_info *info)
{
	if (!info)
		return (0);
	if (pthread_mutex_init(&info->exit_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&info->printing, NULL))
		return (0);
	return (1);
}

int	ft_initialize_philosophers(t_philosopher *index)
{
	int		count;

	if (!index)
		return (0);
	count = index->info->number_of_philosophers;
	while (index && --count >= 0)
	{
		if (pthread_mutex_init(&index->fork, NULL)
			|| pthread_mutex_init(&index->last_time_ate_mutex, NULL)
			|| pthread_mutex_init(&index->times_ate_mutex, NULL))
			return (0);
		index = index->right;
	}
	return (1);
}
