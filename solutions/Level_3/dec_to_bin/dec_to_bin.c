#include <unistd.h>

static void	put_bin(unsigned int n)
{
	char	c;

	if (n >= 2)
		put_bin(n / 2);
	c = n % 2 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	unsigned int	n;
	int				i;

	if (argc == 2)
	{
		n = 0;
		i = 0;
		while (argv[1][i])
			n = n * 10 + (argv[1][i++] - '0');
		put_bin(n);
	}
	write(1, "\n", 1);
	return (0);
}
