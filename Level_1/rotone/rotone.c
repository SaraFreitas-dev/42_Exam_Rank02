/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:18:20 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/07 02:18:20 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	replace_c(char c)
{
	if (((c >= 'A') && (c <= 'Y')) || ((c >= 'a') && (c <= 'y')))
		c += 1;
	else if (c == 'Z')
		c = 'A';
	else if (c == 'z')
		c = 'a';
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
		argv[1][j] = replace_c(argv[1][j]);
		write(1, &argv[1][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}