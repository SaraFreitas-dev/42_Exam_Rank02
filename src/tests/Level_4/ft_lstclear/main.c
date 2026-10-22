#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst, void (*del)(void *));

static int	g_del_calls = 0;

static void	del(void *content)
{
	printf("  del(\"%s\")\n", (char *)content);
	g_del_calls++;
	free(content);
}

static t_list	*build(char **words, int size)
{
	t_list	*head;
	t_list	*node;
	int		i;

	head = NULL;
	for (i = size - 1; i >= 0; i--)
	{
		node = malloc(sizeof(t_list));
		node->content = strdup(words[i]);
		node->next = head;
		head = node;
	}
	return (head);
}

static void	test(char **words, int size)
{
	t_list	*lst;

	g_del_calls = 0;
	lst = build(words, size);
	printf("list of %d node(s):\n", size);
	ft_lstclear(&lst, del);
	printf("  del called %d time(s) | *lst is %s\n\n", g_del_calls,
		lst ? "NOT NULL" : "NULL");
}

int	main(void)
{
	char	*w1[] = {"one", "two", "three"};
	char	*w2[] = {"alone"};

	test(w1, 3);
	test(w2, 1);
	test(NULL, 0);
	ft_lstclear(NULL, del);
	printf("ft_lstclear(NULL, del): no crash\n");
	return (0);
}
