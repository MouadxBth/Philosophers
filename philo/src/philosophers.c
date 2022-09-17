/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:25:58 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 23:30:07 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_info			info;
	t_philosopher	*head;

	if (!ft_check_args(argc))
		return (1);
	if (!ft_fill_info(&info, argc, argv))
		return (1);
	head = NULL;
	ft_create_philosophers(&info, &head);
	ft_start_philosophers(&head);
	ft_check_for_death(head);
	ft_detach(&head);
	ft_cleanup(&head);
	return (0);
}
