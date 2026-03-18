/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:00:23 by sarfreit          #+#    #+#             */
/*   Updated: 2026/03/12 14:00:23 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
int is_space(char c)
{
    if ((c == 32) || ((c >= 9) && (c <= 13)))
        return (1);
    return (0);
}
    void ft_putnbr(int n)
{
    char c;

    if (n >= 10)
    {
        ft_putnbr(n / 10);
    }
    if (n < 0)
    {
        n = -n;
        write(1, "-", 1);
    }
    c = (n % 10) + '0';
    write(1, &c, 1);
}
*/

int is_space(char c)
{
    if ((c == 32) || ((c >= 9) && (c <= 13)))
        return (1);
    return (0);
}


int ft_simple_atoi(char *str)
{
    int res = 0;
    int i = 0;

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
	    i++;
    }
    return (res);
}

void print_hex(int n)
{
    char    *hex_digits;
    char c;

    hex_digits = "0123456789abcdef";
    if (n >= 16)
        print_hex(n / 16);
    c = hex_digits[n % 16];
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int n;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    n = ft_simple_atoi(argv[1]);
    print_hex(n);
    write(1, "\n", 1);
    return (0);
}