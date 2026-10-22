#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

static void	test(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = ft_substr(s, start, len);
	if (!sub)
		printf("ft_substr(\"%s\", %u, %zu) = NULL\n", s, start, len);
	else
		printf("ft_substr(\"%s\", %u, %zu) = \"%s\"\n", s, start, len, sub);
	free(sub);
}

int	main(void)
{
	test("Hello, 42 Porto!", 7, 2);
	test("Hello, 42 Porto!", 0, 5);
	test("Hello, 42 Porto!", 10, 100);
	test("Hello", 0, 0);
	test("Hello", 5, 3);
	test("Hello", 42, 3);
	test("", 0, 5);
	test("abc", 2, 1);
	return (0);
}
