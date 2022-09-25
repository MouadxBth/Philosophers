/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:27:14 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/25 02:30:28 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philosopher	*ft_create_philosopher(t_info *info, int id)
{
	t_philosopher	*result;

	result = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!result)
		return (NULL);
	result->id = id;
	result->is_dead = 0;
	result->is_done = 0;
	result->is_eating = 0;
	result->times_eaten = 0;
	result->last_time_eaten = -1;
	result->start = 0;
	result->left = result;
	result->right = result;
	result->info = info;
	return (result);
}

static int	ft_group_philosopher(t_philosopher **head, t_philosopher *element)
{
	t_philosopher	*last;

	if (!head)
		return (0);
	if (!*head)
	{
		*head = element;
		return (1);
	}
	last = (*head)->left;
	(*head)->left = element;
	element->right = *head;
	element->left = last;
	last->right = element;
	return (1);
}

int	ft_create_philosophers(t_info *info, t_philosopher **head)
{
	int	index;

	index = -1;
	while (++index < info->number_of_philosophers)
	{
		if (!ft_group_philosopher(head,
				ft_create_philosopher(info, index + 1)))
			return (0);
	}
	return (1);
}
