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
    t_list *temp;

    while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
    {
        temp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(temp);
    }
    curr = *begin_list;
    while (curr && curr->next)
    {
        if ((*cmp)(curr->next->data, data_ref) == 0)
        {
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else
            curr = curr->next;
    }
}