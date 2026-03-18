#include "list.h"

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *temp;
    int swap;

    temp = lst;
    if (!lst)
        return (lst);
    while (lst->next)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            // Restart checks from the beginnig
            lst = temp;
        }
        else
            lst = lst->next;
    }
    lst = temp;
    return (lst);
}