// prototype : int closedir(DIR *dir)

// obj : clode a dir stream

// return value : 0 in succes , -1 on success

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
    if (!closedir(dir))
    {
        printf(" dir close succefully\n");
    }
}