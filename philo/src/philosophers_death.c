/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_death.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:26:36 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 22:48:26 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_check_for_death(void *arg)
{
	t_philosopher	*index;
	t_info			*info;
	long			time;
	int				count;

	index = (t_philosopher *)arg;
	info = index->info;
	while (1)
	{
		count = info->number_of_philosophers;
		while (--count >= 0)
		{
			time = ft_milliseconds();
			if (time - ft_last_time_ate(index, -1) > info->time_to_die)
			{
				ft_print_message(index, "dead");
				ft_should_exit(info, 1);
				return (NULL);
			}
			if (ft_done_eating(index) >= info->number_of_philosophers)
				return (ft_should_exit(info, 1), NULL);
			index = index->right;
		}
		ft_msleep(1);
	}
	return (NULL);
}

int	ft_monitor_philosophers(t_philosopher *index, pthread_t *thread)
{
	if (!index || !thread
		|| pthread_create(thread, NULL, ft_check_for_death, index)
		|| pthread_join(*thread, NULL))
		return (0);
	return (1);
}
