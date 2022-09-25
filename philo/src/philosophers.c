/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:25:58 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/25 03:28:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info			info;
	t_philosopher	*head;
//	pthread_t		death;

	if (!ft_check_args(argc))
		return (1);
	if (!ft_fill_info(&info, argc, argv))
		return (1);
	head = NULL;
	if (!ft_create_philosophers(&info, &head))
		return (1);
	if (!ft_init_philosophers(head))
		return (1);
	if (!ft_start_philosophers(head))
		return (1);
	//pthread_create(&death, NULL, ft_check_for_death, head);
	//pthread_join(death, NULL);
	//maprintf("CONTINUING CODE\n");
	ft_await_philosophers(head);
	ft_destroy_mutexes(head);
	ft_free_philosophers(head);
	return (0);
}
