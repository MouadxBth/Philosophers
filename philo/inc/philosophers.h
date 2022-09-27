/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:55:44 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/27 01:09:24 by mbouthai         ###   ########.fr       */
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
	int				minimum_eat_times;
	int				number_of_philosophers;
	int				done_eating;
	int				exit;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long long		start;
	pthread_mutex_t	printing;
	pthread_mutex_t	eating;
}	t_info;

typedef struct s_philosopher
{
	int						id;
	int						is_dead;
	int						is_done;
	int						is_eating;
	int						times_eaten;
	long long				last_time_eaten;
	struct s_philosopher	*right;
	struct s_philosopher	*left;
	pthread_mutex_t			fork;
	pthread_t				thread;
	t_info					*info;
}	t_philosopher;

int			ft_atoi(const char *str);

long long	ft_milliseconds(void);

long long	ft_microseconds(void);

void		ft_usleep(long long time);

void		ft_print_message(t_philosopher *index, char *str);

int			ft_check_args(int argc);

int			ft_validate_info(t_info *info, int argc);

int			ft_fill_info(t_info *info, int argc, char **argv);

int			ft_create_philosophers(t_info *info, t_philosopher **head);

int			ft_init_philosophers(t_philosopher *index);

int			ft_start_philosophers(t_philosopher *index);

void		*ft_begin_cycle(void *arg);

void		*ft_check_for_death(void *arg);

int			ft_should_stop(t_philosopher *philosopher);

void		ft_await_philosophers(t_philosopher *index);

void		ft_destroy_mutexes(t_philosopher *index);

void		ft_free_philosophers(t_philosopher *index);

#endif
