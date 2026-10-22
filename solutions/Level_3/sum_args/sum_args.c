#include <unistd.h>

static int	ft_atoi(char *s)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

static void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	long	sum;
	int		i;

	sum = 0;
	i = 1;
	while (i < argc)
		sum += ft_atoi(argv[i++]);
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
