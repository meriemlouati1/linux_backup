# include "philo.h"

void ft_error(int n)
{
    if (n == 0)
        write(1, "Incorrect numbers of args\n", 26);
    if (n == 1)
        write(1, "Invalid argument\n", 18);
    exit(1);
}
void init_info(t_info * info, int argc, char **argv)
{
    info->num_of_philo = ft_atoi(argv[1]);
    info->time_to_die = ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    info->nb_meals_flag = 0;
    if (argc == 6)
    {
        info->num_of_meals = ft_atoi(argv[5]);
        info->nb_meals_flag = 1;
    }
}
// void *routine(void *str)
// {
//     (void)str;
//     return (NULL);
// }
// void create_philo(t_info info)
// {
//     pthread_t t[info.num_of_philo];
//     t_fork fork[info.num_of_philo];
//     int i = 0;
//     int id;
//     while (i < info.num_of_philo)
//     {
//         pthread_create(&t[i], NULL, &routine, NULL);
//         printf("created the thread, it's id is%d",id);
//         // info.philo.id = i;
//         info.fork.id = i;
//         i++;
//     }
//     info.thread = t;
// }


// int main(int argc, char**argv)
// {
//     t_info info;
//     if (argc !=6 && argc != 5)
//         ft_error(0);
//     init_info(&info, argc, argv);
//     create_philo(info);
// }


void create_fork(t_fork *fork, int n)
 {
    int i;
    i = 0;

    while(i < n)
    {
        fork[i].id = i;
        printf(" fork de i %d\n", fork[i].id);
        i++;
    }
 }

long calcul_time(struct timeval curr_time, struct timeval last_meal)
{
    return((curr_time.tv_sec - last_meal.tv_sec)*1000 +(curr_time.tv_usec - last_meal.tv_usec)/1000);
}

// void *routine (void *str)
// {
//     // (void) str;
//     t_philo *philo;
//     philo = (t_philo *)str;
    
//     struct timeval curr_time;
//     gettimeofday(&philo->fork->time_last_meal, NULL);
//     long time;

//     while (1)
//     {
//         gettimeofday(&curr_time, NULL);
//         time = calcul_time(curr_time, philo->fork->time_last_meal);
//         if (time > philo->info.time_to_die)
//         {
//             printf(" die\n");
//             exit (1);
//         }
//         // if (philo->id % 2 == 0)
//         // {
//         //    pthread_mutex_lock(philo[philo->id].fork->curr_fork);
//         //    pthread_mutex_lock(philo[philo->id].fork->right_fork);
//         // }
//         // else
//         // {

//         // }
//     }
//     printf("hey\n");
//     return (NULL);
// }


long elapsed_time(struct timeval time_last_meal, struct timeval current_time)
{
    return ((current_time.tv_sec - time_last_meal.tv_sec)*1000 + (current_time.tv_usec - time_last_meal.tv_usec)/1000);
}
void execute_philo(t_philo *philo)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    pthread_mutex_lock(philo->fork->right_fork);
    pthread_mutex_unlock(philo->fork->left_fork);

    printf(" philo %d is eating\n", philo->id);
    usleep(philo->info.time_to_eat *1000);
    gettimeofday(&philo->fork->time_last_meal, NULL);
    if (elapsed_time(philo->fork->time_last_meal, current_time) > philo->info.time_to_die)
    {
        printf(" philo %d died", philo->id);
        
    }
}

void *routine (void *arg)
{
    t_philo *philo;
    philo = (t_philo *)malloc(sizeof(t_philo));
    philo = (t_philo *)arg;
    while(1)
    {

        execute_philo(philo);
    }

}



void create_mutex(t_info *info, t_philo *philo)
{
    int i = 0;
    while (i < info->num_of_philo)
    {
        philo[i].fork = malloc(sizeof(t_fork));
        philo[i].fork->mutex_fork = malloc(sizeof(pthread_mutex_t));
        i++;
    }
    while(i < info->num_of_philo)
    {
        pthread_mutex_init(philo[i].fork->mutex_fork, NULL);
        i++;
    }
    i = 0;
    while (i < info->num_of_philo)
    {
        philo[i].fork->left_fork = philo[i].fork->mutex_fork;
        philo[i].fork->right_fork = philo[(i + 1) % info->num_of_philo].fork->mutex_fork;
        i++;
    }
}
void create_philo(t_info *info, t_philo *philo)
{
    int i;
    i = 0;
    while(i < info->num_of_philo)
    {
        philo[i].thread = malloc(sizeof(pthread_t));
        philo[i].id = i;
        philo[i].info = *info;
        int err = pthread_create(philo[i].thread, NULL, &routine, (void *)&philo[i]);
        printf(" thread created id is : %d\n",err);
        i++;
    }
    i = 0;
    while(i < info->num_of_philo)
    {
        pthread_join((*philo[i].thread), NULL);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_info  *info;
    t_philo *philo;

    if (argc != 6 && argc != 5)
        ft_error(0);
    info = (t_info *)malloc(sizeof(t_info));
    init_info(info, argc, argv);
    philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
    if (!philo)
        return(0);
    create_mutex(info, philo);
    create_philo(info, philo);
}
