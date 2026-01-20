/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:43:19 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 17:43:23 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    t_list  *current;
    int     counter;

    counter = 0;
    current = begin_list;
    while (current)
    {
        current = current->next;
        counter++;
    }
    return (counter);
}