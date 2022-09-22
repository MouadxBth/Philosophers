/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_eating_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:42:07 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/20 16:14:08 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_check_eating(void *arg)
{
	t_philosopher	*index;
	int				count;

	index = (t_philosopher *)arg;
	count = index->info->number_of_philosophers;
	while (--count >= 0)
	{
		sem_wait(index->info->done);
		if (count - 1 >= 0)
		{
			sem_post(index->info->eating);
			sem_post(index->info->printing);
		}
	}
	sem_post(index->info->exit);
	return (NULL);
}
