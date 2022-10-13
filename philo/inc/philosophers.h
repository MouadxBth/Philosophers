/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:55:44 by mbouthai          #+#    #+#             */
/*   Updated: 2022/10/13 22:20:44 by mbouthai         ###   ########.fr       */
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
	pthread_mutex_t	exit_mutex;
}	t_info;

typedef struct s_philosopher
{
	int						id;
	int						times_ate;
	long					last_time_ate;
	struct s_philosopher	*left;
	struct s_philosopher	*right;
	pthread_t				thread;
	pthread_mutex_t			fork;
	pthread_mutex_t			last_time_ate_mutex;
	pthread_mutex_t			times_ate_mutex;
	t_info					*info;
}	t_philosopher;

int		ft_atoi(const char *str);

long	ft_milliseconds(void);

void	ft_msleep(long milliseconds);

void	ft_print_message(t_philosopher *philosopher, char *msg);

int		ft_times_ate(t_philosopher *index, int n);

int		ft_should_exit(t_info *info, int n);

int		ft_done_eating(t_philosopher *index);

long	ft_last_time_ate(t_philosopher *index, long n);

int		ft_fill_info(t_info *info, int argc, char **argv);

int		ft_create_philosophers(t_info *info, t_philosopher **head);

int		ft_initialize_info(t_info *info);

int		ft_initialize_philosophers(t_philosopher *index);

int		ft_start_philosophers(t_philosopher *index);

void	*ft_begin_cycle(void *arg);

void	*ft_check_for_death(void *arg);

int		ft_monitor_philosophers(t_philosopher *index, pthread_t *thread);

int		ft_await_philosophers(t_philosopher *index);

int		ft_destroy_mutexes(t_philosopher *index);

void	ft_free_philosophers(t_philosopher *index);

#endif
