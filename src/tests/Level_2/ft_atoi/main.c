#include <stdio.h>

int	ft_atoi(const char *str);

/* Prints the string with invisible characters shown, e.g. \t. */
static void	show(const char *s)
{
	putchar('"');
	for (; *s; s++)
	{
		if (*s == '\t')
			printf("\\t");
		else if (*s == '\n')
			printf("\\n");
		else if (*s == '\v')
			printf("\\v");
		else if (*s == '\f')
			printf("\\f");
		else if (*s == '\r')
			printf("\\r");
		else
			putchar(*s);
	}
	putchar('"');
}

static void	test(const char *s)
{
	printf("ft_atoi(");
	show(s);
	printf(") = %d\n", ft_atoi(s));
}

int	main(void)
{
	test("42");
	test("-42");
	test("+42");
	test("0");
	test("-0");
	test("   123");
	test(" \t\n\v\f\r 456");
	test("12abc34");
	test("abc");
	test("");
	test("--5");
	test("+-5");
	test("-+5");
	test("- 5");
	test("  -00123");
	test("2147483647");
	test("-2147483648");
	return (0);
}
