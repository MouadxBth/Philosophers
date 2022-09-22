/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:55:44 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/22 08:35:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				number_of_philosophers;
	int				minimum_eat_times;
	int				done_eating;
	int				exit;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start;
	pthread_mutex_t	printing;
	pthread_mutex_t	eating;
}	t_info;

typedef struct s_philosopher
{
	int						id;
	int						is_dead;
	int						is_done;
	int						times_eaten;
	long					last_time_eaten;
	struct s_philosopher	*right;
	struct s_philosopher	*left;
	pthread_mutex_t			fork;
	pthread_t				thread;
	t_info					*info;
}	t_philosopher;

int		ft_atoi(const char *str);

int		ft_check_args(int argc);

int		ft_validate_info(t_info *info, int argc);

int		ft_fill_info(t_info *info, int argc, char **argv);

long	ft_current_time(void);

void	ft_usleep(long time);

void	ft_print_message(t_philosopher *philosopher, char *str);

void	ft_create_philosophers(t_info *info, t_philosopher **head);

void	ft_start_philosophers(t_philosopher **head);

void	ft_check_for_death(t_philosopher *head);

void	*ft_begin_cycle(void *arg);

void	ft_detach(t_philosopher **head);

void	ft_cleanup(t_philosopher **head);

#endif
