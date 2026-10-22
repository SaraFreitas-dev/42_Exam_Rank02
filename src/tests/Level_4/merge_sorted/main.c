#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	*merge_sorted(int *a, int size_a, int *b, int size_b);

static void	print_tab(int *t, int size)
{
	int	i;

	printf("[");
	for (i = 0; i < size; i++)
		printf("%s%d", i ? ", " : "", t[i]);
	printf("]");
}

static void	test(int *a, int sa, int *b, int sb)
{
	int	*res;

	res = merge_sorted(a, sa, b, sb);
	printf("merge_sorted(");
	print_tab(a, sa);
	printf(", ");
	print_tab(b, sb);
	printf(") = ");
	if (!res)
		printf("NULL\n");
	else
	{
		print_tab(res, sa + sb);
		printf("\n");
	}
	free(res);
}

int	main(void)
{
	int	a1[] = {1, 3, 5};
	int	b1[] = {2, 4, 6};
	int	a2[] = {1, 2, 3};
	int	b2[] = {10, 20};
	int	a3[] = {-5, 0, 0, 7};
	int	b3[] = {-10, 0, 8, 8, 9};
	int	a4[] = {42};
	int	a5[] = {INT_MIN, 0};
	int	b5[] = {-1, INT_MAX};

	test(a1, 3, b1, 3);
	test(a2, 3, b2, 2);
	test(b2, 2, a2, 3);
	test(a3, 4, b3, 5);
	test(a4, 1, NULL, 0);
	test(NULL, 0, a4, 1);
	test(NULL, 0, NULL, 0);
	test(a5, 2, b5, 2);
	printf("originals untouched: %d %d %d | %d %d %d\n",
		a1[0], a1[1], a1[2], b1[0], b1[1], b1[2]);
	return (0);
}
