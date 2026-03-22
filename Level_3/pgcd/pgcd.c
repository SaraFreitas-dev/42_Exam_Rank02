/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:31:17 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/21 17:31:17 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("\n");
        return (0);
    }
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    int i;
    if (n1 > n2)
        i = n2;
    else
        i = n1;
    while (i > 0)
    {
        if ((n1 % i == 0) && (n2 % i == 0))
        {
            printf("%d\n", i);
            return (0);
        }
        i--;
    }
    return (0);
}