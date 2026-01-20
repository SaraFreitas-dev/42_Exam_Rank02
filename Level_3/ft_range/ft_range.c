/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:44:06 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 19:14:39 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int *arr;
    int i;
    int nbr;

    if (end > start)
        arr = malloc(((end - start) + 1) * sizeof(int));
    else if (end < start)
        arr = malloc(((start - end) + 1) * sizeof(int));
    else
        arr = malloc(sizeof(int));
    if (!arr)
        return (0);
    i = 0;
    nbr = start;
    if (end > start)
        while (nbr <= end)
            arr[i++] = nbr++;
    else if (start > end)
        while (nbr >= end)
            arr[i++] = nbr--;
    else
        arr[i] = start;
    return (arr);
}

/*
#include <stdio.h>

int main(void)
{
    int *nums = ft_range(0,-2);
    int i = 0;
    
    while (i < 3)
    {
        printf("%d\n", nums[i]);
        i++;
    }
    free(nums);
    return (0);
}*/