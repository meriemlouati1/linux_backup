# include "philo.h"

void ft_error(int n)
{
    if (n == 0)
        write(1, "Incorrect nbr of arguments\n", 28);
    if (n == 1)
        write(1, "Invalid argument\n", 17);
    exit(1);
}
long ft_atoi(char *str)
{
    int i ;
    long result;

    i = 0;
    result = 0;
    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            ft_error(1);
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (result >= INT_MAX || result <= INT_MIN)
        ft_error(1);
    return(result);
}