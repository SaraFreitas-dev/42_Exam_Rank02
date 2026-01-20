/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:23:26 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 19:18:19 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int *arr;
    int nbr;
    int i;
    
    if (start > end)
        arr = malloc((start - end + 1) * sizeof(int));
    else if (end > start)
        arr = malloc((end - start + 1) * sizeof(int));
    else
        arr = malloc(sizeof(int));
    if (!arr)
        return (0);
    nbr = end;
    i = 0;
    if (start > end)
        while (nbr <= start)
            arr[i++] = nbr++;
    else if (end > start)
        while (nbr >= start)
            arr[i++] = nbr--;
    else
        arr[i] = nbr;
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