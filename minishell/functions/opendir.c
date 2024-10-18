
 // obj : open a directory and returned a pointer to dir stream

 // prototype : dir *opendir(const char *name) 
 //  name od the file to open  can be absolute path (from root) 
 // or relative path 

// return value : in success pointer to dir stream
// null if the dir can't be opened 

// DIR data type that represent a dir stream
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>

int main()
{
    DIR *dir = opendir("new direcory");  // dir doesnt exit 
    if (dir)
        printf(" directory opened succefully\n");
    else
        printf("failed to open directory\n");


    DIR *dir = opendir(".");  // current dir
    if (dir)
        printf(" directory opened succefully\n");
    else
        printf("failed to open directory\n");


    DIR *dir = opendir("../");  // parent dir 
    if (dir)
        printf(" directory opened succefully\n");
    else
        printf("failed to open directory\n");
}