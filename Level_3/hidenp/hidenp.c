/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:18:41 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 19:30:31 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int hidenp(char *s1, char *s2)
{
    while (*s1)
    {
        while (*s2 && (*s1 != *s2))
            s2++;
        if (*s1 != *s2)
            return (0);
        s1++;
        s2++;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    if (hidenp(argv[1], argv[2]))
        write(1, "1\n", 2);
    else
        write(1, "0\n", 2);
    return (0);
}