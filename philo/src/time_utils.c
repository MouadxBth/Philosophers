/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:33:23 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 15:33:37 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_milliseconds(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_msleep(long milliseconds)
{
	long	start;

	start = ft_milliseconds();
	usleep(milliseconds * 900);
	while (ft_milliseconds() < start + milliseconds)
		usleep(milliseconds);
}
