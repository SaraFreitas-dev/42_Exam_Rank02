/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:02:39 by sarfreit          #+#    #+#             */
/*   Updated: 2026/02/19 22:21:12 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
        i++;
    if ((str[i] == '-') || (str[i] == '+'))
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while ((str[i] >= '0') && (str[i] <= '9'))
    {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return (res * sign);
}

void ft_putnbr(int n)
{
    char    c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i;
    int num;
    int res;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    num = ft_atoi(argv[1]);
    res = 0;
    while (i <= 9)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(num);
        write(1, " = ", 3);
        ft_putnbr(i * num);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}