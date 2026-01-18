/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:35:34 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/18 14:35:34 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int	check_chars(char *str1, char *str2)
{
	while (*str1)
	{
		while (*str2 && (*str2 != *str1))
			str2++;
		if (*str2 != *str1)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (check_chars(argv[1], argv[2]) == 1)
		while (*argv[1])
			write(1, argv[1]++, 1);
	write(1, "\n", 1);
	return (0);
}
