/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:27:25 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 16:39:33 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_start_philosophers(t_philosopher *index)
{
	t_info	*info;
	int		count;

	if (!index)
		return (0);
	count = -1; 
	info = index->info;
	info->start = ft_milliseconds();
	while (index && ++count < info->number_of_philosophers)
	{
		if (pthread_create(&index->thread, NULL, ft_begin_cycle, index))
			return (0);
		index = index->right;
	}
	return (1);
}
