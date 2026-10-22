#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

static void	test(char *src)
{
	char	*dup;

	dup = ft_strdup(src);
	if (!dup)
	{
		printf("ft_strdup(\"%s\") returned NULL\n", src);
		return ;
	}
	printf("ft_strdup(\"%s\") = \"%s\" | new memory: %s\n", src, dup,
		dup != src ? "yes" : "no");
	free(dup);
}

int	main(void)
{
	test("Hello");
	test("");
	test("a");
	test("42 Porto rocks");
	test("with\ttab and spaces  ");
	return (0);
}
