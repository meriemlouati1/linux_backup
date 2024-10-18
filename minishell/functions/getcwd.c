// obj: get the current working director
// copies the absolutepath of the current working directory
// to the buffer pointed to by buff that has the size size

// prototype: char *getcwd(char *buff, size_t size);


// return value: string
// in success : buff is returned, if the length of the absolute path
// is bigger to the length of buff null is returned 

# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
int main()
{
    // example with large size
    char *buff = (char *)malloc(4000*sizeof(char));
    char *str = getcwd(buff, 4000);
    printf("%s\n", str);
    free(buff);

    // example with small buff
    char *buff = (char *)malloc(4*sizeof(char));
    char *str = getcwd(buff, 4);
    printf("%s\n", str);
    if (errno == ERANGE)   // errno is defined n the the hedear file errno.h
        printf(" yes");     // ERANGE : means buffer too small 
    free(buff);


}

