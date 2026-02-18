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

unsigned int    ft_hcf(unsigned int a, unsigned int b)
{
    unsigned int    min_div;
    unsigned int    value;

    min_div = 0;
    if (a < b)
        value = a;
    else
        value = b;
    while (value > 0)
    {
        if ((a % value == 0) && (b % value == 0))
            min_div = value;
        value--;
    }
    return (min_div);
}
  
unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int    hcf;
    unsigned int    result;

    hcf = ft_hcf(a, b);
    if (!a || !b || (a == 0) || (b == 0))
        return (0);
    result = (a * b) / hcf;
    return (result);
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