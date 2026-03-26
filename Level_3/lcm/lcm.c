/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:52:09 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 19:52:38 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int i;
    if (a > b)
        i = a;
    else
        i = b;
    if ((a == 0) || (b == 0))
        return (0);
    while (1)
    {
        if ((i % a == 0) && (i % b == 0))
            return (i);
        i++;
    }
}
/*
#include <stdio.h>

int main(void)
{
    unsigned int    a = 8;
    unsigned int    b = 12;
    
    printf("%d", lcm(a, b));
    
    return (0);
}*/