// prototype : struct dirent *readdir(DIR *DRIP)

// obj : return a pointer to the next entry in the dir stream 
// pointed to by DRIP , it return NULL when reaching end of direct
// steam or when error occurs

# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>

int main()
{
    DIR *dir = opendir(".");
    struct dirent *dirent = readdir(dir);
    while(dirent)
    {
        printf(" name is %s", dirent->d_name);
        printf(" inode id %ld\n", dirent->d_ino);
        dirent = readdir(dir);
    }
}