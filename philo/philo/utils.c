# include "philo.h"

long ft_atoi(char *str)
{
    int i;
    int signe;
    long result;

    i = 0;
    signe = 1;
    result = 0;
    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            ft_error(1);
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 +(str[i] - '0');
        i++;
    }
    if (result * signe >= INT_MAX || result * signe <= INT_MIN )
        ft_error(1);
    return (result * signe);
}