#include <stdio.h>
#include <stdlib.h>

void fprime(int n)
{
    int i;
    int first;

    i = 2;
    first = 1;
    if (n == 1)
    {
        printf("1");
        return ;
    }
    while (n > 1)
    {
        if (n % i == 0)
        {
            if (!first)
                printf("*");
            printf("%d", i);
            n /= i;
            first = 0;
        }
        else
            i++;
    }
}

int main(int argc, char **argv)
{
    int n;

    if (argc != 2)
    {
        printf("\n");
        return (0);
    }
    n = atoi(argv[1]);
    fprime(n);
    printf("\n");
    return (0);
}