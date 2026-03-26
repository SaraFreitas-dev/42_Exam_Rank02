<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:38:57 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/15 22:38:57 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int max(int* tab, unsigned int len)
{
    unsigned int i;
    int largest_n;
    i = 1;
    
    if (len == 0)
        return (0);
    largest_n = tab[0];
    while ((i < len))
    {
        if (tab[i] > largest_n)
            largest_n = tab[i];
        i++;
    }
    return (largest_n);
}

/*
#include <stdio.h>

int main(void)
{
    int myNumbers[] = {25, 0, 1000, 50, 75, 100};
    printf("%d", max(myNumbers, 3));
    return (0);
}
*/
