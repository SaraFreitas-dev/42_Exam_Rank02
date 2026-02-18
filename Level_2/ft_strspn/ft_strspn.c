/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:37:35 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/15 21:37:35 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && accept[j])
	{
		if (s[i] == accept[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

/*
 The strspn() function calculates the length (in bytes) of the initial segment of s which consists entirely of bytes in accept.
 The strspn() function returns the number of bytes in the initial segment of s which consist only of bytes from accept.

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*s = "abc";
	char	*accept = "";

	printf("ORIGINAL: %ld\n", strspn(s, accept));
	printf("MY FUNCTION: %ld\n", ft_strspn(s, accept));

	return (0);
}
*/