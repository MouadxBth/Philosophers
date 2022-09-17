/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_create_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:27:14 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/17 00:56:48 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static t_philosopher	*ft_create_philosopher(t_info *info, int id)
{
	t_philosopher	*result;

	result = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!result)
		return (NULL);
	result->id = id;
	result->pid = -1;
	result->is_dead = 0;
	result->times_eaten = 0;
	result->last_time_eaten = -1;
	result->left = result;
	result->right = result;
	result->info = info;
	return (result);
}

static void	ft_group_philosopher(t_philosopher **head, t_philosopher *element)
{
	t_philosopher	*last;

	if (!head)
		return ;
	if (!*head)
	{
		*head = element;
		return ;
	}
	last = (*head)->left;
	(*head)->left = element;
	element->right = *head;
	element->left = last;
	last->right = element;
}

void	ft_create_philosophers(t_info *info, t_philosopher **head)
{
	int	index;

	index = -1;
	while (++index < info->number_of_philosophers)
		ft_group_philosopher(head,
			ft_create_philosopher(info, index + 1));
}
