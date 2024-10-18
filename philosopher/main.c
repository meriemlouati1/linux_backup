#include "philo.h"


void init_info(t_info *info,int argc, char **argv)
{
    info->nb_philo = ft_atoi(argv[1]);
    info->time_to_die = ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    info->start_time = (struct timeval *)malloc(sizeof(struct timeval));
    info->current_time = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(info->start_time, NULL);
    if (argc == 6)
        info->nb_meals = ft_atoi(argv[5]);
    else    
        info->nb_meals = -1;
}
int elapsed_time(struct timeval *current_time, struct timeval *last_time_eat)
{
    int elapsed_time;;
    elapsed_time = ((current_time->tv_sec - last_time_eat->tv_sec)*1000 + (current_time->tv_usec -last_time_eat->tv_usec)/1000);
    return (elapsed_time);
}
// void print_msg(t_philo *philo)
// {
//     int time_stamp;
//     time_stamp = ((philo->current_time->tv_sec - philo->info->start_time->tv_sec)*1000 + (philo->current_time->tv_usec -philo->info->start_time->tv_usec)/1000);
//     printf(" %d philo %d is eating\n", time_stamp, philo->id);
// }

void print_msg_lock(t_philo *philo, char *str)
{
    pthread_mutex_lock(philo->msg);
    gettimeofday(philo->info->current_time, NULL);
    printf("%d philo %d %s\n", elapsed_time(philo->info->current_time, philo->info->start_time),philo->id, str);
    pthread_mutex_unlock(philo->msg);
}
void *routine(void *arg)
{
    t_philo *philo = (t_philo *)(arg);
    pthread_mutex_init(philo->msg, NULL);
    // printf("enterd the thread and thread id is %d\n", philo->id);
    // gettimeofday(philo->current_time, NULL);
    if (!(philo->id %2))
    {
        pthread_mutex_lock(philo->left_fork);
        print_msg_lock(philo, "has taken a fork (left_fork)");
        pthread_mutex_lock(philo->right_fork);
        print_msg_lock(philo, "has taken a fork (right_fork)");
        // print_msg(philo);
        // printf("philo %d is eating\n", philo->id);
        print_msg_lock(philo, " is eating ");
        usleep((philo->info->time_to_eat)*1000);
        gettimeofday(philo->last_time_eat, NULL);
        // printf("last time eat %d : last_time.tv_sec %ld last_time.tv_usec % ld\n", philo->id, (*philo->last_time_eat).tv_sec, (*philo->last_time_eat).tv_usec);
        // printf("current_time %d : current_time.tv_sec %ld current_time.tv_usec % ld\n", philo->id, (*philo->current_time).tv_sec, (*philo->current_time).tv_usec);
        // printf(" elapsed time %d\n", elapsed_time(philo->current_time, philo->last_time_eat));
        // if (elapsed_time(philo->current_time, philo->last_time_eat) > philo->info->time_to_die)
        //     print_msg_lock(philo, "died");
        // printf("philo %d died\n", philo->id);
        pthread_mutex_unlock(philo->left_fork);
        print_msg_lock(philo, "put down a fork (right_fork)");
        pthread_mutex_unlock(philo->right_fork);
        print_msg_lock(philo, "put down a fork (left_fork)");
        // printf("philo %d is sleeping\n", philo->id);
        print_msg_lock(philo, " is sleeping");
        usleep((philo->info->time_to_sleep)*1000);
        // printf("philo %d is thinking\n", philo->id);
        print_msg_lock(philo, " is thinking");

    }
    else
    {
        // printf("philo %d is sleeping\n", philo->id);
        print_msg_lock(philo, " is sleeping");
        usleep((philo->info->time_to_sleep)*1000);
        // printf("philo %d is thinking\n", philo->id);
        print_msg_lock(philo, " is thinking");
        pthread_mutex_lock(philo->right_fork);
        print_msg_lock(philo, "has taken a fork (right_fork)");
        pthread_mutex_lock(philo->left_fork);
        print_msg_lock(philo, "has taken a fork (left_fork)");
        // print_msg(philo); 
        // printf("philo %d is eating\n", philo->id);
        print_msg_lock(philo, " is eating ");
        usleep((philo->info->time_to_eat)*1000);
        // printf("last time eat %d : last_time.tv_sec %ld last_time.tv_usec % ld\n", philo->id, (*philo->last_time_eat).tv_sec, (*philo->last_time_eat).tv_usec);
        // printf("current_time %d : current_time.tv_sec %ld current_time.tv_usec % ld\n", philo->id, (*philo->current_time).tv_sec, (*philo->current_time).tv_usec);
        // printf("%d\n", elapsed_time(philo->current_time, philo->last_time_eat));
        // if (elapsed_time(philo->current_time, philo->last_time_eat) > philo->info->time_to_die)
        //     print_msg_lock(philo, "died");
        // printf("philo %d died\n", philo->id);
        gettimeofday(philo->last_time_eat, NULL);
        pthread_mutex_unlock(philo->right_fork);
        print_msg_lock(philo, "put down a fork (right_fork)");
        pthread_mutex_unlock(philo->left_fork);
        print_msg_lock(philo, "put down a fork (left_fork)");

    }
    return (NULL);
}

void create_fork(t_fork *fork, t_info *info)
{
    int i = 0;
    while(i < info->nb_philo)
    {
        fork[i].fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        fork->id = i + 1;
        i++;
    }
    i = 0;
    while(i < info->nb_philo)
    {
        pthread_mutex_init(fork[i].fork, NULL);
        i++;
    }
    
}
void *monitor_fun(void *arg)
{
    t_philo *philo = (t_philo *)(arg);
    while(1)
    {
        int i = 0;
        gettimeofday(philo[i].current_time, NULL);
        while(i < philo->info->nb_philo)
        {
            int t = elapsed_time(philo[i].current_time, philo[i].last_time_eat);
            if(t > philo->info->time_to_die)
            {
                printf("\n t is %d \n", t);
                print_msg_lock(&philo[i], "died");
                exit(1);
            }
            i++;
        }
        // i = 0;
        // while( i< philo->info->nb_philo)
        // {

        // }
    }
    return(NULL);
}
void create_monitor(t_philo *philo)
{
    pthread_t *monitor = (pthread_t *)malloc(sizeof(pthread_t));
    if(pthread_create(monitor, NULL, monitor_fun, philo))
    {
        write(1, "Error creating monitor\n", 23);
        exit(1);
    }
    printf(" hey from monitor\n");
}

void create_philo(t_philo *philo, t_fork *fork, t_info *info)
{
    int i = 0;
    info->monitor = (pthread_t *)malloc(sizeof(pthread_t));

    if(pthread_create(info->monitor, NULL, monitor_fun, philo))
    {
        write(1, "Error creating monitor\n", 23);
        exit(1);
    }
    while(i < info->nb_philo)
    {
        philo[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
        philo[i].current_time = (struct timeval *)malloc(sizeof(struct timeval));
        philo[i].last_time_eat = (struct timeval *)malloc(sizeof(struct timeval));
        gettimeofday(philo[i].current_time, NULL);
        gettimeofday(philo[i].last_time_eat, NULL);
        philo[i].id = i + 1;
        philo[i].right_fork = fork[i].fork;
        philo[i].left_fork = fork[((i + 1)%(info->nb_philo))].fork;
        philo[i].info = info;
        philo[i].msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if(pthread_create(philo[i].thread, NULL, routine, &philo[i]))
        {
            write(1, "Error creating thread\n", 22);
            exit(1);
        }
        i++;
    }
    if(pthread_create(info->monitor, NULL, monitor_fun, philo))
    {
        write(1, "Error creating monitor\n", 23);
        exit(1);
    }
    i = 0;
    while(i < info->nb_philo)
    {
        if(pthread_join(*(philo[i].thread), NULL))
        {
            write(1, "Error joining thread\n", 21);
            exit(1);
        }
        i++;
    }
    if(pthread_join(*(info->monitor), NULL))
    {
        write(1, "Error joining monitor\n", 22);
        exit(1);
    }
}



void test_philo_content(t_philo *philo, t_info *info)
{
    int i;
    i = 0;
    while(i < info->nb_philo)
    {
        printf("\n philo n %d\n", philo[i].id);
        printf(" time to eat %d\n", philo[i].info->time_to_eat);
        printf(" time to die %d\n", philo[i].info->time_to_die);
        printf(" time to sleep %d\n", philo[i].info->time_to_sleep);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_info *info;
    t_philo *philo;
    t_fork  *fork;
    info = NULL;
    if (argc!= 5 && argc != 6)
        ft_error(0);
    info = (t_info *)malloc(sizeof(t_info));
    init_info(info, argc, argv);
    philo = (t_philo *)malloc(sizeof(t_philo)*info->nb_philo);
    fork = (t_fork *)malloc(sizeof(t_fork)*info->nb_philo);
    create_fork(fork, info);
    create_philo(philo, fork, info);
}