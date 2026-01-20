/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:52:57 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 20:14:27 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int i)
{
    char c;

    if (i >= 10)
        ft_putnbr(i / 10);
    c = (i % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int     i;
    if (argc < 2)
    {
        write(1, "0\n", 2);
        return (0);
    }
    i = 1;
    while (argv[i])
        i++;
    ft_putnbr(i - 1);
    write(1, "\n", 1);
    return (0);
}