/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:03:05 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/25 02:26:10 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_philosophers(t_philosopher *index)
{
	t_info	*info;
	int		count;

	if (!index)
		return (0);
	info = index->info;
	if (pthread_mutex_init(&info->printing, NULL))
		return (0);
	count = -1;
	while (index && ++count < info->number_of_philosophers)
	{
		if (pthread_mutex_init(&index->fork, NULL))
			return (0);
		index = index->right;
	}
	return (1);
}
