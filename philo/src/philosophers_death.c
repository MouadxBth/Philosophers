/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_death.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:36 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/22 08:41:03 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_check_for_death(t_philosopher *head)
{
	long	time;
	t_info	*info;

	info = head->info;
	while (1)
	{
		if (info->exit)
			return ;
		time = ft_current_time();
		if (time - head->last_time_eaten >= info->time_to_die)
		{
			pthread_mutex_lock(&head->info->printing);
			printf("%ld %i has died\n", ft_current_time() - head->info->start, head->id);
			return ;
		}
		head = head->right;
	}
}
