/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:44:30 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 22:19:56 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_error(char *msg, int ret)
{
	return (printf("[ERROR]: %s.\n", msg), ret);
}

static int	ft_check_args(int argc)
{
	if (argc - 1 < 4)
		return (ft_error("Not enough arguments"));
	else if (argc - 1 > 5)
		return (ft_error("Too much arguments"));
	return (1);
}

static int	ft_validate_info(t_info *info, int argc)
{
	if (!info || info->number_of_philosophers <= 0)
		return (ft_error("Number of philosophers can't be less or equal to 0"));
	if (info->time_to_die < 0)
		return (ft_error("Time to die cannot be less than 0"));
	if (info->time_to_eat < 0)
		return (ft_error("Time to eat cannot be less than 0"));
	if (info->time_to_sleep < 0)
		return (ft_error("Time to sleep cannot be less than 0"));
	if (argc - 1 == 5 && info->minimum_eat_times <= 0)
		return (ft_error("Minimum eating times can't be less or equal than 0"));
	return (1);
}

int	ft_fill_info(t_info *info, int argc, char **argv)
{
	if (!ft_check_args(argc))
		return (0);
	if (argc - 1 == 5)
		info->minimum_eat_times = ft_atoi(argv[5]);
	else
		info->minimum_eat_times = -1;
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->done_eating = 0;
	info->exit = 0;
	info->start = -1;
	return (ft_validate_info(info, argc));
}
