/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:32:46 by sarfreit          #+#    #+#             */
/*   Updated: 2026/02/21 23:32:46 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *curr;
    t_list *prev;

    curr = *begin_list;
    prev = 0;
    while (curr)
    {
        if ((cmp)(curr->data, data_ref) == 0)
        {
            temp = curr->next;
            free(curr);
        }
        else
            curr = curr->next;
    }
}