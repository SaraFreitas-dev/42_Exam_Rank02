/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 00:35:18 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/07 00:35:18 by sarfreit         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int	j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = args_len(argv[1]) - 1;
	while (j >= 0)
	{
		write(1, &argv[1][j], 1);
		j--;
	}
	write(1, "\n", 1);
	return (0);
}
