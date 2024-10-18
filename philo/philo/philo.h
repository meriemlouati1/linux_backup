# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <sys/time.h>
#include <time.h>


// typedef struct s_info
// {
//     pthread_t *thread;
//     int num_of_philo;
//     int time_to_die;
//     int time_to_eat;
//     int time_to_sleep;
//     int num_of_meals;
//     t_philo philo;
//     t_fork fork;
// } t_info;


// typedef struct s_philo
// {
//     int     id;
//     t_fork  *left;
//     t_fork  *right;
// } t_philo;


// typedef struct s_fork
// {
//     int id;
// }t_fork;


// typedef struct s_philo
// {
//     pthread_t   *thread;
//     int         num_of_philo;
//     int         time_to_die;
//     int         time_to_eat;
//     int         time_to_sleep;
//     int         num_of_meals;
// }t_philo;



typedef struct s_info
{
    int num_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_meals;
    int nb_meals_flag;
}t_info;

typedef struct s_fork
{
    int id;
    struct timeval time_last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *mutex_fork;
}t_fork;

typedef struct s_philo
{
    int id;
    pthread_t *thread;
    t_info  info;
    t_fork  *fork;
    pthread_mutex_t *message;
    pthread_mutex_t *last_time_eat;
    pthread_mutex_t *philo_died;
    pthread_mutex_t *nb_meals;
}t_philo;



long ft_atoi(char *str);
void ft_error(int n);