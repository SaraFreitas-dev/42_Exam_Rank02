int	ft_sqrt(int nb)
{
	long	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (nb > 0 && i * i == nb)
		return ((int)i);
	return (0);
}
