/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 09:31:23 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/06 09:31:23 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char argv)
{
	if ((argv == ' ') || (argv == '	'))
		return (1);
	return (0);
}

int	args_len(char *argv)
{
	int	j;

	j = 0;
	while (argv[j])
		j++;
	return (j);
}

int	main(int argc, char *argv[])
{
	int	j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = args_len(argv[1]) - 1;
	while ((j >= 0) && (is_space(argv[1][j]) == 1))
		j--;
	while ((j >= 0) && (is_space(argv[1][j]) == 0))
		j--;
	j++;
	while ((is_space(argv[1][j]) == 0) && argv[1][j])
	{
		write(1, &argv[1][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
