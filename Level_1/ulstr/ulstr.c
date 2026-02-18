/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:53:51 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/07 19:53:51 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	upside_down(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		c -= 32;
	else if ((c >= 'A') && (c <= 'Z'))
		c += 32;
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
		argv[1][j] = upside_down(argv[1][j]);
		write(1, &argv[1][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
