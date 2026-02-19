/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:11:55 by sarfreit          #+#    #+#             */
/*   Updated: 2026/02/19 21:58:02 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int is_space(char c)
{
    if (((c >= 9) && (c <= 32)) || (c == 32))
        return (1);
    return (0);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    capitalizer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_space(str[i + 1]) || (str[i + 1] == '\0'))
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
    while (i < argc)
    {
        capitalizer(argv[i]);
        ft_putchar('\n');
        i++;
    }
    return (0);
}