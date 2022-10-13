/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:12:05 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 18:10:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info			info;
	t_philosopher	*head;
	pthread_t	death;

	head = NULL;
	if (!ft_fill_info(&info, argc, argv))
		return (1);
	if (!ft_create_philosophers(&info, &head))
		return (1);
	if (!ft_initialize_info(&info))
		return (ft_free_philosophers(head), 1);
	if (!ft_initialize_philosophers(head))
		return (ft_free_philosophers(head), 1);
	if (!ft_start_philosophers(head))
		return (ft_free_philosophers(head), 1);
	if (!ft_monitor_philosophers(head, &death))
		return (ft_free_philosophers(head), 1);
	if (!ft_await_philosophers(head))
		return (ft_free_philosophers(head), 1);
	if (!ft_destroy_mutexes(head))
		return (ft_free_philosophers(head), 1);
	ft_free_philosophers(head);
	return (0);
}
