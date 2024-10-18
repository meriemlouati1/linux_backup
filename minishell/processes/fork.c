// obj : create a duplicate process of the calling process
// prototype : pid_t fork(void)
// return values : in succes O is returned in the child process
// and child's process pid in the parent process 
// in failure  -1 in parent process , no child process is created


// if we call fork n times , we wil have 2^n process
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>

// int main()
// {
//     printf(" test the fork function\n");
//     printf("this is good from the process id %d\n", getpid());
//     fork();
//     printf("this good from the process id : %d\n", getpid());
//     return (0);
// }


int main()
{
    int id = fork();
    int n ;
    if (id == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }
    if(id != 0)
    {
        wait(NULL);
    }

    int i;
    i = n;
    while(i < n +5)
    {
        printf("%d", i);
        i++;
    }
    if (id != 0)
    {
        printf("\n");
    }
}