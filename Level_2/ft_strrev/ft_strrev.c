/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:09:17 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/15 20:09:17 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	len -= 1;
	while (len > i)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
    char s[] = "Hello??";
    ft_strrev(s);
    printf("%s\n", s);
    return (0);
}
*/