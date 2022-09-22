/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_start_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:27:25 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/20 15:47:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_start_philosophers(t_philosopher *index)
{
	int				count;

	if (!index)
		return ;
	index->info->start = ft_current_time();
	count = index->info->number_of_philosophers;
	while (index && --count >= 0)
	{
		index->last_time_eaten = index->info->start;
		index->pid = fork();
		if (!index->pid)
			ft_begin_cycle(index);
		else if (index->pid < 0)
			exit(1);
		index = index->right;
	}
}
