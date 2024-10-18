# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
    {
        printf("invalid args");
        exit(1);
    }
    char *str = readline("This is minishell >>");
    printf("%s", str);
    
}