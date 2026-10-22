#include <stddef.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject);

static void	test(const char *s, const char *reject)
{
	printf("ft_strcspn(\"%s\", \"%s\") = %zu\n", s, reject,
		ft_strcspn(s, reject));
}

int	main(void)
{
	test("hello world", " ");
	test("hello", "xyz");
	test("hello", "");
	test("", "abc");
	test("", "");
	test("abcdef", "fed");
	test("42 Porto", "0123456789");
	test("Porto 42", "0123456789");
	test("aaa", "a");
	return (0);
}
