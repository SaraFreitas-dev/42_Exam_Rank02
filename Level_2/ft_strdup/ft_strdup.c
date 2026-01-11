/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:32:11 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/11 22:32:11 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	char	*dest;
	int		i;


	dest = malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
The  strdup() function returns a pointer to a new string which is a duplicate
       of the string s.  Memory for the new string is obtained with  malloc(3),  and
       can be freed with free(3).

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "Hello";
	char	*str2 = strdup(str1);
	char	*str3 = ft_strdup(str1);

	printf("ORIGINAL: %s\n", str2);
	printf("MY FUNCTIONN: %s", str3);

	return (0);
}
*/