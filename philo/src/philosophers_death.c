/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_death.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:36 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/25 02:25:35 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_check_for_death(void *arg)
{
	t_philosopher	*index;
	t_info			*info;
	long long		time;

	index = (t_philosopher *)arg;
	info = index->info;
	while (!info->exit)
	{
		time = ft_milliseconds();
		if (time - index->last_time_eaten > info->time_to_die)
		{
			ft_print_message(index, "died");
			info->exit = 1;
			index->is_dead = 1;
		}
		if (ft_should_stop(index))
			return (NULL);
	}
	return (NULL);
}
