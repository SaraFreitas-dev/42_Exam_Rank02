/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:13:53 by sarfreit          #+#    #+#             */
/*   Updated: 2026/02/18 23:34:30 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_simple_atoi(char *str)
{
    int res = 0;
    int i = 0;

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res *= 10;
	res += str[i++] - '0';
    }
    return (res);
}

void    print_hex(int n)
{
    char    *hex_digits;

    hex_digits = "0123456789abcdef";
    if (n >= 16)
        print_hex(n / 16);
    n = hex_digits[n % 16];
    write(1, &n, 1);
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
}
    return (0);
}
