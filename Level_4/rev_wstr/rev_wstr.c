#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	end;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	i--;

	while (i >= 0)
	{
		while (i >= 0 && is_space(argv[1][i]))
			i--;
		end = i;
		while (i >= 0 && !is_space(argv[1][i]))
			i--;
		if (end >= 0)
		{
			write(1, &argv[1][i + 1], end - i);
			if (i > 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}