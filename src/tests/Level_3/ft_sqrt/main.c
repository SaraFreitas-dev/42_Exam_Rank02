#include <limits.h>
#include <stdio.h>

int	ft_sqrt(int nb);

static void	test(int n)
{
	printf("ft_sqrt(%d) = %d\n", n, ft_sqrt(n));
}

int	main(void)
{
	test(0);
	test(1);
	test(2);
	test(4);
	test(9);
	test(10);
	test(16);
	test(25);
	test(26);
	test(144);
	test(-4);
	test(INT_MIN);
	test(2147395600);
	test(INT_MAX);
	return (0);
}
