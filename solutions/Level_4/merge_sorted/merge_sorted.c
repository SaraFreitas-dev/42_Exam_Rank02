#include <stdlib.h>

int	*merge_sorted(int *a, int size_a, int *b, int size_b)
{
	int	*res;
	int	i;
	int	j;
	int	k;

	if (size_a + size_b == 0)
		return (NULL);
	res = malloc(sizeof(int) * (size_a + size_b));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (i < size_a && j < size_b)
	{
		if (a[i] <= b[j])
			res[k++] = a[i++];
		else
			res[k++] = b[j++];
	}
	while (i < size_a)
		res[k++] = a[i++];
	while (j < size_b)
		res[k++] = b[j++];
	return (res);
}
