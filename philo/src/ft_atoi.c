/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:25:45 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/16 23:25:49 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_negative(const char *str, int *i)
{
	int	negative;

	negative = 1;
	if (str[*i] == '-')
	{
		negative = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
	{
		*i = *i + 1;
	}
	return (negative);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	resultat;

	i = 0;
	resultat = 0;
	while (str[i] == ' '
		|| str[i] == '\t'
		|| str[i] == '\v'
		|| str[i] == '\r'
		|| str[i] == '\n'
		|| str[i] == '\f')
	{
		i++;
	}
	negative = ft_negative(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (negative * resultat);
}
