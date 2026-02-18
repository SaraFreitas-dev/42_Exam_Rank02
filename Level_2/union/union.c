/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:14:30 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/18 14:14:30 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int	verify_char(char *str, char c, int index)
{
	int	i;

	i = 0;
	while ((i < index) && (str[i]))
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	j;
	int	k;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = 0;
	while (argv[1][j])
	{
		if (verify_char(argv[1], argv[1][j], j) == 1)
			write(1, &argv[1][j], 1);
		j++;
	}
	k = 0;
	while (argv[2][k])
	{
		if ((verify_char(argv[1], argv[2][k], j) == 1) 
			&& (verify_char(argv[2], argv[2][k], k) == 1))
			write(1, &argv[2][k], 1);
		k++;
	}
	write(1, "\n", 1);
	return (0);
}
