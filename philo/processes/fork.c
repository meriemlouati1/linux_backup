# include <stdio.h>
#include <sys/types.h>
# include <unistd.h>
// int main(int argc, char**argv)
// {
//     printf("hey\n");
//     int id = fork();
//     printf(" hello world\n");
//     if (id == 0)
//         printf("hello from the child process\n");
//     if (id != 0)
//         printf("hello from the parent process\n");
//     return(0);
// }

int main(int argc, char **argv)
{
    int x = 2;
    int pid = fork();

    if (pid == 0)
        x++;
    printf(" the value of x is %d\n", x);
}