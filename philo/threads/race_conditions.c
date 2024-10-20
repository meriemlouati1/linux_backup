# include <pthread.h>
# include <unistd.h>
# include <stdio.h>


//  example of race condition


// int mails = 0;

// void *routine(void *str)
// {
//     for (int i =0; i< 100000; i++)
//         mails++;
//     return(NULL);
// }

// int main(int argc, char **argv)
// {
//     pthread_t t1;
//     pthread_t t2;

//     pthread_create(&t1, NULL, &routine, NULL);
//     pthread_create(&t2, NULL, &routine, NULL);

//     pthread_join(t1, NULL);
//     pthread_join(t2, NULL);
//     printf("NUmber of mails :%d\n", mails);
//     return(0);
// }


// solve race conditions

int mails = 0;
pthread_mutex_t mutex;

void *routine(void *str)
{
    for (int i =0; i< 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return(NULL);
}

int main(int argc, char **argv)
{
    pthread_t t1;
    pthread_t t2;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    
    printf("Number of mails :%d\n", mails);
    return(0);
}
