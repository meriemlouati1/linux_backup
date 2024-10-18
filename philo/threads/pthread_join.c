# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

# define th 100
// void make_coffe(char *name)
// {
//     printf("Barista %s is making coffe..\n", name);
//     sleep(3);
//     printf(" coffe is ready\n");
// }
// int main()
// {
//     make_coffe("luca");
//     make_coffe("Paolo");
// }

// void *make_coffee(void *data)
// {
//     printf("Barista is making coffe\n");
//     sleep(3);
//     printf("coffe is ready\n");
//     return (NULL);
// }
// int main()
// {
//     pthread_t baristas[500];
//     int i = 0;
//     while(i < 500)
//     {
//         pthread_create(baristas + i, NULL, make_coffee, NULL);
//         i++;
//     }
//     i = 0;
//     while(i < 500)
//     {
//         pthread_join(baristas[i], NULL);
//         i++;
//     }
//     return (0);
// }

// race conditions :

int ldg;
pthread_mutex_t ldg_lock;
void *update_ldg(void *str)
{
    (void)str;
    pthread_mutex_lock(&ldg_lock);
    ldg++;
    pthread_mutex_unlock(&ldg_lock);
    return (NULL);
}
int main()
{
    pthread_t waiter[th];
    int i = 0;
    pthread_mutex_init(&ldg_lock, NULL);
    while( i < th)
    {
        pthread_create(waiter +i, NULL, update_ldg, NULL);
        i++;
    }
    i = 0;
    while(i < th)
    {
        pthread_join(waiter[i], NULL);
        i++;
    }
    printf("%d\n", ldg);
}