#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <pthread.h>


typedef struct s_info
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_meals;
}   t_info;

typedef struct s_philo
{
    int id;
    pthread_t   *thread;
    pthread_mutex_t

}   t_philo;


#endif