/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:54:06 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/10 20:54:06 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;		
		}
		i++;
	}
	return (i);
}

/*
The  strcspn()  function  calculates  the  length of the initial segment of s
which consists entirely of bytes not in reject.
This function returns the number of characters in the first string before the 1st occurrence
of character present in second string.

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello!";
	char	str2[] = "!e";

	printf("Original strcspn: %ld\n", strcspn(str1, str2));
	printf("My strcspn: %ld\n", ft_strcspn(str1, str2));

	return (0);
}
*/