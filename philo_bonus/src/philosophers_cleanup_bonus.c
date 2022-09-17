/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_cleanup_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 03:22:37 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/17 01:14:59 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_kill(t_philosopher *index)
{
	int	count;

	if (!index)
		return ;
	sem_wait(index->info->exit);
	count = index->info->number_of_philosophers;
	while (index && --count >= 0)
	{
		kill(index->pid, SIGTERM);
		index = index->right;
	}
}

void	ft_detach(t_philosopher *index)
{
	int	count;
	int	status;

	if (!index)
		return ;
	count = index->info->number_of_philosophers;
	status = -1;
	while (index && --count >= 0)
	{
		waitpid(index->pid, &status, 0);
		index = index->right;
	}
	if (index->info->eating != NULL)
		sem_close(index->info->eating);
	sem_close(index->info->forks);
	sem_close(index->info->printing);
}

void	ft_cleanup(t_philosopher *index)
{
	t_philosopher	*temp;
	int				count;

	if (!index)
		return ;
	count = index->info->number_of_philosophers;
	while (index && --count >= 0)
	{
		temp = index;
		if (temp)
			free(temp);
		index = index->right;
	}
}
