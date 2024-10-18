// obj : checks if the fie can be accessed
// if the file can be written to , read from, executed

// prototype : int access(const char 8 pathname, int mode);

// int mode :
// F_OK : FILE EXITS
// R_OK : CAN BE READ
// W_OK : CAN BE WRITTEN
// X_OK : CAN BE EXECUTED

// return value : succes : 0 error : -1

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int main()
{
    int value = access("test.txt", F_OK);   // valid file
    if (value == 0)
        printf(" file exit\n");
    value = access("test.txt", R_OK);  // readeble file
    if (value == 0)
        printf(" file can be read\n");  
    value = access("test.txt", W_OK);  // writable file
    if (value == 0)
        printf(" file can be written\n");  
    value = access("test.txt", X_OK);   // non_executable for the 1 time
    if (value == 0)
        printf(" file can be executed\n");
    value = access("cc.c", F_OK);         // non_existed file
    if (value != 0)
        printf(" file doesn't exits\n"); 
    return (0);
}