/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_cleanup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:22:37 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 23:29:35 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_detach(t_philosopher **head)
{
	t_philosopher	*index;
	int				count;

	if (!head || !*head)
		return ;
	index = *head;
	count = index->info->number_of_philosophers;
	while (index && --count >= 0)
	{
		pthread_detach(index->thread);
		index = index->right;
	}
}

void	ft_cleanup(t_philosopher **head)
{
	t_philosopher	*index;
	t_philosopher	*temp;
	int				count;

	if (!head || !*head)
		return ;
	index = *head;
	count = index->info->number_of_philosophers;
	if (index->info->minimum_eat_times > 0)
		pthread_mutex_destroy(&index->info->eating);
	while (index && --count >= 0)
	{
		pthread_mutex_destroy(&index->fork);
		temp = index;
		index = index->right;
		if (temp)
			free(temp);
	}
}
