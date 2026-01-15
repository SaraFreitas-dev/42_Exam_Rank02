/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:14:04 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/15 19:14:04 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/*
The strpbrk() function returns a pointer to the byte in s that matches one of
the bytes in accept, or NULL if no such byte is found.

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "Hello!";
	char	*search = "e!";
	char	*str2 = strpbrk(str1, search);
	char	*str3 = ft_strpbrk(str1, search);

	printf("ORIGINAL: %s\n", str2);
	printf("MY FUNCTION: %s", str3);

	return (0);
}
*/