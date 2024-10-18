// obj : change the working dir of the calling process
// to directory specified in path


// prototye : int chdir (const char *path);

// return value : 0 on success , -1 on failure
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main()
{
    char *buffer = (char *)malloc(4000*sizeof(char));
    char *str = getcwd(buffer, 4000);
    printf(" the current working dir before is :\n %s\n", str);
    int value = chdir("../mini");
    if (value == 0)
        printf(" path changed\n");
    str = getcwd(buffer, 4000);
    printf(" the current working dir after is :\n %s\n", str);
    free(buffer);
    return (0);
}