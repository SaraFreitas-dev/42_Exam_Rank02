#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);

static void	test(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = ft_split(s, c);
	printf("ft_split(\"%s\", '%c') = ", s, c);
	if (!tab)
	{
		printf("NULL\n");
		return ;
	}
	printf("[");
	for (i = 0; tab[i]; i++)
	{
		printf("%s\"%s\"", i ? ", " : "", tab[i]);
		free(tab[i]);
	}
	printf("] (%d words)\n", i);
	free(tab);
}

int	main(void)
{
	test("Hello 42 Porto", ' ');
	test("   lots   of   spaces   ", ' ');
	test("", ' ');
	test("     ", ' ');
	test("noseparator", ' ');
	test("a,b,,c,", ',');
	test(",,,start", ',');
	test("one", 'o');
	return (0);
}
