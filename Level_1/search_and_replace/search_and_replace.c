/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:53:57 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/07 03:53:57 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	args_len(char *argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

int	is_equal(char argv1, char argv2)
{
	if (argv1 == argv2)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	j;

	if ((argc != 4) || (args_len(argv[2]) > 1) || (args_len(argv[3]) > 1))
	{
		write(1, "\n", 1);
		return (0);
	}
	j = 0;
	while (argv[1][j])
	{
		if (is_equal(argv[1][j], argv[2][0]) == 1)
			argv[1][j] = argv[3][0];
		write(1, &argv[1][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
