/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:44:49 by sarfreit          #+#    #+#             */
/*   Updated: 2026/02/19 21:58:08 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_space(char c)
{
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return (1);
    return (0);
}

char ft_to_upper(char c)
{
    if ((c >= 'a') && (c <= 'z'))
        c -= 32;
    return (c);
}

char ft_to_lower(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        c += 32;
    return (c);
}

void    capitalizer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((i == 0) || (is_space(str[i - 1])))
            str[i] = ft_to_upper(str[i]);
        else
            str[i] = ft_to_lower(str[i]);
        ft_putchar(str[i++]);
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc <= 1)
    {
        ft_putchar('\n');
        return (0);
    }
    i = 1;
    while (argv[i])
    {
        capitalizer(argv[i]);
        ft_putchar('\n');
        i++;
    }
    return (0);
}