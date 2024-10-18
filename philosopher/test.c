# include "philo.h"

pthread_mutex_t msg = PTHREAD_MUTEX_INITIALIZER;

void *routine(void *str)
{
    t_philo *philo = (t_philo *)str;
    if((philo->id)%2 == 0)
    {
        pthread_mutex_lock(&msg);
        printf("hey from pair philo %d\n", philo->id);
        sleep(1);
        pthread_mutex_unlock(&msg);
    }
    else
    {
        pthread_mutex_lock(&msg);
        printf("hey from impair philo %d \n", philo->id);
        sleep(1);
        pthread_mutex_unlock(&msg);
    }
    return(NULL);
}
int main()
{
    t_philo *philo;
    philo = (t_philo *)malloc(sizeof(t_philo)*1000);
    int i = 0;
    while(i <1000)
    {
        philo[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
        philo[i].id = i + 1;
        pthread_create(philo[i].thread,NULL, routine, &philo[i]);
        i++;
    }
    i = 0;
    while(i < 1000)
    {
        pthread_join(*(philo[i].thread), NULL);
        i++;
    }
}