#include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*lst_reverse(t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	while (lst)
	{
		next = lst->next;
		lst->next = prev;
		prev = lst;
		lst = next;
	}
	return (prev);
}
