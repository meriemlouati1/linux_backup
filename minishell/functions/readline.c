//  readline function:
// obj: read aline from the terminal and return it
// prompt a custom message to indicate to the user to write
//  if prompt == NULL or empty string, nothig is issued
// the string returned is allocated and must be freed after
// the final newline is not returned
// prototype : char *readline(char *prompt)

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

int main()
{
    printf("%s\n",readline("here message >>"));
    return (0);
}
