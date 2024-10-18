# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

void *function1();
void *function2();


pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;    //mutex lock

int main()
{
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init (&second_mutex, NULL);  // initialize the lock

    pthread_t one;
    pthread_t two;

    pthread_create(&one, NULL, function1, NULL);  //create thread
    pthread_create(&two, NULL, function2, NULL);

    pthread_join(one, NULL); 
    pthread_join(two, NULL);

    printf("thread joined\n");
}


void *function1()
{
    pthread_mutex_lock(&first_mutex); // acquire the ressource, mutex lock
    printf(" Thread ONE acquired first_mutex\n");
    sleep(1);
    pthread_mutex_lock(&second_mutex);
    printf(" Thread ONE acquired the second mutex\n");
    pthread_mutex_unlock(&second_mutex);
    printf(" Thread ONE released the second mutex\n");
    return (NULL);
}


void *function2()
{
    pthread_mutex_lock(&second_mutex);
    printf("Thread TWO acquired the second_mutex\n");
    sleep(1);
    pthread_mutex_lock(&first_mutex);
    printf("Thread TWO acquired the first_mutex\n");
    pthread_mutex_unlock(&first_mutex);
    printf(" Thread TWO released the first_mutex\n");
    return (NULL);
}