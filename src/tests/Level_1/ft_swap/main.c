#include <limits.h>
#include <stdio.h>

void	ft_swap(int *a, int *b);

static void	test(int a, int b)
{
	int	x;
	int	y;

	x = a;
	y = b;
	ft_swap(&x, &y);
	printf("ft_swap(%d, %d) -> a = %d, b = %d\n", a, b, x, y);
}

int	main(void)
{
	test(1, 2);
	test(42, -42);
	test(0, 0);
	test(7, 7);
	test(INT_MIN, INT_MAX);
	return (0);
}
