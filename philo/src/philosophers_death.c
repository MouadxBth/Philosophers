/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_death.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:36 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 23:26:39 by mbouthai         ###   ########.fr       */
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
		if (info->minimum_eat_times > 0
			&& info->done_eating >= info->number_of_philosophers)
		{
			pthread_mutex_lock(&head->info->printing);
			return ;
		}
		time = ft_current_time();
		if (time - head->last_time_eaten >= info->time_to_die)
		{
			ft_print_message(head, "died");
			return ;
		}
		head = head->right;
	}
}
