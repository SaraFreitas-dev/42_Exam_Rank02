#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

static void	test(char const *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (!res)
		printf("ft_strjoin(\"%s\", \"%s\") = NULL\n", s1, s2);
	else
		printf("ft_strjoin(\"%s\", \"%s\") = \"%s\" | new memory: %s\n",
			s1, s2, res, (res != s1 && res != s2) ? "yes" : "no");
	free(res);
}

int	main(void)
{
	test("Hello, ", "42!");
	test("", "");
	test("abc", "");
	test("", "xyz");
	test("42", " Porto");
	test("a", "b");
	return (0);
}
