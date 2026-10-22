#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

/* Only the sign matters (man strcmp), so we print -1, 0 or 1. */
static void	test(char *s1, char *s2)
{
	int	r;

	r = ft_strcmp(s1, s2);
	printf("ft_strcmp(\"%s\", \"%s\") -> %s\n", s1, s2,
		r < 0 ? "negative" : (r > 0 ? "positive" : "zero"));
}

int	main(void)
{
	test("abc", "abc");
	test("abc", "abd");
	test("abd", "abc");
	test("", "");
	test("", "a");
	test("a", "");
	test("abc", "ab");
	test("ab", "abc");
	test("Hello", "hello");
	test("42", "42 Porto");
	return (0);
}
