# ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <pthread.h>
#include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_info
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_meals;
    struct timeval *start_time;
    struct  timeval *current_time;
    pthread_t *monitor;
} t_info;

typedef struct s_philo
{
    int id;
    struct timeval *current_time;
    struct timeval *last_time_eat;
    pthread_t *thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_info *info;
    pthread_mutex_t *msg;
}t_philo;

typedef struct s_fork
{
    int id;
    pthread_mutex_t *fork;
}t_fork;


void ft_error(int n);
long ft_atoi(char *str);


#endif