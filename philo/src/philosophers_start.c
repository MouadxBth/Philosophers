/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:27:25 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/20 03:55:21 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_start_philosophers(t_philosopher **head)
{
	t_philosopher	*index;
	int				count;

	index = *head;
	index->info->start = ft_current_time();
	count = index->info->number_of_philosophers;
	while (index && --count >= 0)
	{
		index->last_time_eaten = index->info->start;
		pthread_create(&index->thread, NULL, ft_begin_cycle, index);
		index = index->right;
	}
}
