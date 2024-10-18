# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

int x =2;
void *routine(void *str)
{
    x++;
    printf("hello from thread\n");
    sleep(3);
    printf("Ending thread\n");
    printf(" the process id is %d\n", getpid());
    printf("value of x is %d \n", x);
    return(NULL);
}

void *routine2(void *str)
{
    x++;
    printf("hello from thread\n");
    sleep(3);
    printf("Ending thread\n");
    printf(" the process id is %d\n", getpid());
    printf("value of x is %d\n", x);
    return(NULL);
}
int main(int argc, char **argv)
{
    pthread_t t1;
    pthread_t t2;
    

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    return(0);
}

