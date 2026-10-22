#include <stdio.h>

int	ft_strlen(char *str);

static void	test(char *s)
{
	printf("ft_strlen(\"%s\") = %d\n", s, ft_strlen(s));
}

int	main(void)
{
	test("");
	test("a");
	test("Hello, 42!");
	test("   spaces   ");
	test("tab\there");
	test("a very long string to make sure the loop works fine");
	return (0);
}
