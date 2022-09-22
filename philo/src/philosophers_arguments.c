/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:44:30 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/20 03:47:48 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_args(int argc)
{
	if (argc - 1 < 4)
		return (printf("Not enough arguments!\n"), 0);
	else if (argc - 1 > 5)
		return (printf("too much args\n"), 0);
	return (1);
}

int	ft_validate_info(t_info *info, int argc)
{
	if (!info || info->number_of_philosophers <= 0)
		return (0);
	if (info->time_to_die < 0)
		return (0);
	if (info->time_to_eat < 0)
		return (0);
	if (info->time_to_sleep < 0)
		return (0);
	if (argc - 1 == 5)
	{
		if (info->minimum_eat_times <= 0)
			return (0);
		pthread_mutex_init(&info->eating, NULL);
	}
	info->exit = 0;
	pthread_mutex_init(&info->printing, NULL);
	return (1);
}

int	ft_fill_info(t_info *info, int argc, char **argv)
{
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc - 1 == 5)
		info->minimum_eat_times = ft_atoi(argv[5]);
	else
		info->minimum_eat_times = -1;
	info->done_eating = 0;
	return (ft_validate_info(info, argc));
}
