/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 04:18:29 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/06 04:18:29 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char argv)
{
	if ((argv == ' ') || (argv == '	'))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	j;

	j = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while ((is_space(argv[1][j]) == 1) && argv[1][j])
		j++;
	while ((is_space(argv[1][j]) == 0) && argv[1][j])
	{
		write(1, &argv[1][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
