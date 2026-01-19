/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:44:35 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/19 20:02:46 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_word(char c)
{
	if ((c == 32) || ((c >= 9) && (c <= 13)))
		return (0);
	return (1);	
}

int	main(int argc, char *argv[])
{
	int	i;
	int	space;
	int	printed;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	space = 0;
	printed = 0;
	while (argv[1][i])
	{
		while (is_word(argv[1][i]) == 0)
		{
			space = 1;
			i++;
		}
		if (!argv[1][i])
			break;
		if ((space == 1) && (printed == 1))
			write(1, " ", 1);
		space = 0;
		printed = 1;
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
