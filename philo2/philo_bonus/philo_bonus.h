/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukurekc <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:08:13 by bukurekc          #+#    #+#             */
/*   Updated: 2023/07/17 12:08:15 by bukurekc         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_philo
{
	size_t		philo_id;
	size_t		total_nbr_of_meals;
	time_t		time_of_last_meal;
	int			nbr_of_meals;
}	t_philo;

typedef struct s_arg
{
	pthread_t	mealchecker_tid;
	pthread_t	deathchecker_tid;	
	pid_t		*pid_philo;
	sem_t		*write_sem;
	sem_t		*fork_sem;
	sem_t		*stop;
	sem_t		*eat_enough;
	int			nbr_philo;
	time_t		start_time;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	size_t		nbr_of_meals;
	t_philo		philo;
}	t_data;

void	ft_taking_forks_eating(t_data *data);
void	ft_sleeping_thinking(t_data *data);
void	*ft_routine(void *data);
void	*ft_eatchecker(void *arg);
void	*ft_death_checker(void *arg);
void	ft_usleep(int ms);
void	ft_init_philo(t_data *data);

long	ft_time(void);
int		ft_init_datas(t_data *data, int ac, char **av);
int		ft_atoi(const char *str);
int		ft_is_digit(char *str);
int		ft_printf(char *arr, ...);

#endif
