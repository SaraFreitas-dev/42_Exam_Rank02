#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*lst_reverse(t_list *lst);

static void	print_list(t_list *lst)
{
	printf("[");
	while (lst)
	{
		printf("\"%s\"%s", (char *)lst->content, lst->next ? " -> " : "");
		lst = lst->next;
	}
	printf("]\n");
}

static t_list	*build(t_list *n, char **words, int size)
{
	int	i;

	for (i = 0; i < size; i++)
	{
		n[i].content = words[i];
		n[i].next = (i < size - 1) ? &n[i + 1] : NULL;
	}
	return (size ? &n[0] : NULL);
}

static void	test(t_list *n, char **words, int size)
{
	t_list	*lst;
	t_list	*res;

	lst = build(n, words, size);
	printf("before: ");
	print_list(lst);
	res = lst_reverse(lst);
	printf("after:  ");
	print_list(res);
	printf("same nodes reused: %s\n\n",
		(size == 0 && !res) || (size && res == &n[size - 1]) ? "yes" : "no");
}

int	main(void)
{
	t_list	n[5];
	char	*w1[] = {"one", "two", "three", "four", "five"};
	char	*w2[] = {"42", "Porto"};
	char	*w3[] = {"alone"};

	test(n, w1, 5);
	test(n, w2, 2);
	test(n, w3, 1);
	test(n, NULL, 0);
	return (0);
}
