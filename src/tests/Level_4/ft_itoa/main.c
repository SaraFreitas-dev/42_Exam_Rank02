#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr);

static void	test(int n)
{
	char	*s;

	s = ft_itoa(n);
	printf("ft_itoa(%d) = \"%s\"\n", n, s ? s : "(null)");
	free(s);
}

int	main(void)
{
	test(0);
	test(1);
	test(-1);
	test(42);
	test(-42);
	test(10);
	test(100);
	test(-1000);
	test(123456789);
	test(INT_MAX);
	test(INT_MIN);
	return (0);
}
