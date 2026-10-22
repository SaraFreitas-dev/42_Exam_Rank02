#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2);

static void	test(char *src)
{
	char	buf[64];
	char	*ret;
	int		i;

	for (i = 0; i < 63; i++)
		buf[i] = 'X';
	buf[63] = '\0';
	ret = ft_strcpy(buf, src);
	printf("ft_strcpy(buf, \"%s\") -> buf = \"%s\" | returns buf: %s\n",
		src, buf, ret == buf ? "yes" : "no");
}

int	main(void)
{
	test("Hello");
	test("");
	test("a");
	test("42 Porto rocks");
	test("with\ttab");
	return (0);
}
