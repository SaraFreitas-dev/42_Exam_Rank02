#include <stdlib.h>

int count_digits(int n)
{
    int count;

    count = 0;
    if (n <= 0)
        count++;
    while (n)
    {
        n /= 10;
        count++;
    }
    return (count);
}

char *ft_itoa(int n)
{
    char    *str;
    int     len;
    long    nbr;

    nbr = n;
    len = count_digits(n);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (0);
    str[len] = '\0';
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
    if (nbr == 0)
        str[0] = '0';
    while (nbr > 0)
    {
        str[len - 1] = (nbr % 10) + '0';
        nbr /= 10;
        len--;
    }
    return (str);
}