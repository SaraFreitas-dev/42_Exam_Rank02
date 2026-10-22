#include <stdio.h>

int	vowel_count(char *str);

static void	test(char *s)
{
	printf("vowel_count(\"%s\") = %d\n", s, vowel_count(s));
}

int	main(void)
{
	test("hello");
	test("");
	test("AEIOU aeiou");
	test("rhythm");
	test("Porto");
	test("yYyY");
	test("The quick brown fox jumps over the lazy dog");
	test("12345 !?");
	return (0);
}
