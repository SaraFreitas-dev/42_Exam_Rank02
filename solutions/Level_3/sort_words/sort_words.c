#include <unistd.h>

static int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

static void	put_line(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char	*tmp;
	int		i;
	int		j;

	if (argc < 2)
		return (write(1, "\n", 1), 0);
	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
		put_line(argv[i++]);
	return (0);
}
