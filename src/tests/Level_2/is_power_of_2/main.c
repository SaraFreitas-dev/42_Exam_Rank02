#include <stdio.h>

int	is_power_of_2(unsigned int n);

static void	test(unsigned int n)
{
	printf("is_power_of_2(%u) = %d\n", n, is_power_of_2(n));
}

int	main(void)
{
	test(0);
	test(1);
	test(2);
	test(3);
	test(4);
	test(6);
	test(16);
	test(31);
	test(64);
	test(1023);
	test(1024);
	test(65536);
	test(2147483648u);
	test(4294967295u);
	return (0);
}
