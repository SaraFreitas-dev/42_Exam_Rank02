#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);

static void	test(t_list *lst, int size)
{
	t_list	*last;

	last = ft_lstlast(lst);
	if (!last)
		printf("list of %d node(s) -> NULL\n", size);
	else
		printf("list of %d node(s) -> \"%s\"\n", size, (char *)last->content);
}

int	main(void)
{
	t_list	n[5];
	char	*words[] = {"one", "two", "three", "four", "five"};
	int		i;

	for (i = 0; i < 5; i++)
	{
		n[i].content = words[i];
		n[i].next = (i < 4) ? &n[i + 1] : NULL;
	}
	test(NULL, 0);
	test(&n[4], 1);
	test(&n[3], 2);
	test(&n[0], 5);
	return (0);
}
