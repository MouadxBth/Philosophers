/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:56:41 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/26 23:58:21 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_should_stop(t_philosopher *index)
{
	t_info	*info;

	if (!index)
		return (0);
	info = index->info;
	if (info->exit || index->is_dead)
		return (1);
	if (info->minimum_eat_times > 0
		&& info->done_eating
		>= info->number_of_philosophers)
			info->exit = 1;
	return (info->exit);
}
