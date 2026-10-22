int	vowel_count(char *str)
{
	int		count;
	char	c;

	count = 0;
	while (*str)
	{
		c = *str++;
		if (c >= 'A' && c <= 'Z')
			c += 32;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			count++;
	}
	return (count);
}
