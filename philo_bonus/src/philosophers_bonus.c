/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:25:58 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/20 16:13:52 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_info			info;
	pthread_t		thread;
	t_philosopher	*head;

	if (!ft_check_args(argc))
		return (1);
	if (!ft_fill_info(&info, argc, argv))
		return (1);
	head = NULL;
	ft_create_philosophers(&info, &head);
	ft_start_philosophers(head);
	if (info.minimum_eat_times > 0)
		pthread_create(&thread, NULL, ft_check_eating, head);
	ft_kill(head);
	ft_detach(head);
	ft_cleanup(head);
	return (0);
}
