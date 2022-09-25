/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_cleanup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:22:37 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/25 02:24:45 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_await_philosophers(t_philosopher *index)
{
	t_info	*info;
	int				count;

	if (!index)
		return ;
	info = index->info;
	count = -1;
	while (index && ++count < info->number_of_philosophers)
	{
		//printf("WAITING %i\n", index->id);
		pthread_join(index->thread, NULL);
		//printf("DONE %i\n", index->id);
		index = index->right;
	}
}

void	ft_destroy_mutexes(t_philosopher *index)
{
	t_info			*info;
	int				count;

	if (!index)
		return ;
	info = index->info;
	count = -1;
	if (info->minimum_eat_times > 0)
		pthread_mutex_destroy(&info->eating);
	while (index && ++count < info->number_of_philosophers)
	{
		pthread_mutex_destroy(&index->fork);
		index = index->right;
	}
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
