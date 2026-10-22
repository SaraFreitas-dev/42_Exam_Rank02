#include <unistd.h>

static int	only_digits(char *s)
{
	if (!*s)
		return (0);
	while (*s)
		if (*s < '0' || *s++ > '9')
			return (0);
	return (1);
}

static long	to_long(char *s)
{
	long	n;

	n = 0;
	while (*s)
		n = n * 10 + (*s++ - '0');
	return (n);
}

static int	is_prime(long n)
{
	long	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	first;
	int	len;

	first = 1;
	i = 1;
	while (i < argc)
	{
		if (only_digits(argv[i]) && is_prime(to_long(argv[i])))
		{
			if (!first)
				write(1, " ", 1);
			len = 0;
			while (argv[i][len])
				len++;
			write(1, argv[i], len);
			first = 0;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
