#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*dup_word(char const *s, int len)
{
	char	*w;
	int		i;

	w = malloc(len + 1);
	if (!w)
		return (NULL);
	i = -1;
	while (++i < len)
		w[i] = s[i];
	w[len] = '\0';
	return (w);
}

static char	**free_all(char **tab, int n)
{
	while (n--)
		free(tab[n]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		len;

	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		tab[i] = dup_word(s, len);
		if (!tab[i])
			return (free_all(tab, i));
		i++;
		s += len;
	}
	tab[i] = NULL;
	return (tab);
}
