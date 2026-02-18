/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:38:21 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/08 22:38:21 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	mirror_c(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		c = 'z' - (c - 'a');
	else if ((c >= 'A') && (c <= 'Z'))
		c = 'Z' - (c - 'A');
	return (c);
}

int	main(int argc, char *argv[])
{
	int	j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = 0;
	while (argv[1][j])
	{
		argv[1][j] = mirror_c(argv[1][j]);
		write(1, &argv[1][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}