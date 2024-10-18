//  obj: clears the history of previousy entered commands
// after callig this function , the history will be empty 
//  user can't retrieve previous commands
//  frees the memory used by theh history list

// prototype: void rl_clear_history(void);

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>


int main()
{
    add_history(" Command 1");
    add_history(" Command 2");


    printf(" Current history: \n");
    HIST_ENTRY **the_history = history_list();
    int i = 0;
    while(the_history[i])
    {
        printf(" %d: %s\n", i, the_history[i]->line);
        i++;
    }
    rl_clear_history();
    printf(" History after clear : \n");
    the_history = history_list();
    if (the_history == NULL || the_history[0] == NULL)
    {
        printf(" No history\n");
    }
    else
    {
        int empty = 1;
        i = 0;
        while (the_history[i]) {
            if (the_history[i]->line != NULL && the_history[i]->line[0] != '\0') {
                printf("History not cleared at index %d: %s\n", i, the_history[i]->line);
                empty = 0;
            }
            i++;
        }
        if (empty) {
            printf("History cleared (all entries are NULL or empty)\n");
        }
    }
}
