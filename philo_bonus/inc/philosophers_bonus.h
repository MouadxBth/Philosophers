/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:39:15 by mbouthai          #+#    #+#             */
/*   Updated: 2022/09/27 01:14:01 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/wait.h>

typedef struct s_info
{
	int				number_of_philosophers;
	int				minimum_eat_times;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start;
	sem_t			*printing;
	sem_t			*forks;
	sem_t			*eating;
	sem_t			*done;
	sem_t			*exit;
}	t_info;

typedef struct s_philosopher
{
	int						id;
	int						pid;
	int						is_dead;
	int						is_done;
	int						times_eaten;
	long					last_time_eaten;
	struct s_philosopher	*right;
	struct s_philosopher	*left;
	t_info					*info;
}	t_philosopher;

int		ft_atoi(const char *str);

int		ft_check_args(int argc);

int		ft_validate_info(t_info *info, int argc);

int		ft_fill_info(t_info *info, int argc, char **argv);

long	ft_milliseconds(void);

void	ft_usleep(long time);

void	ft_print_message(t_philosopher *philosopher, char *str);

sem_t	*ft_new_semaphore(char *name, int value);

void	ft_create_philosophers(t_info *info, t_philosopher **head);

void	ft_start_philosophers(t_philosopher *head);

void	*ft_check_for_death(void *arg);

void	*ft_check_eating(void *arg);

void	ft_begin_cycle(t_philosopher *philosopher);

void	ft_kill(t_philosopher *index);

void	ft_detach(t_philosopher *index);

void	ft_cleanup(t_philosopher *index);

#endif
