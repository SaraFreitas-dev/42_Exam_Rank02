/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:22:46 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/14 14:22:46 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_and_upper(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		c += 32;
		ft_putchar('_');
	}
	ft_putchar(c);
}

int	main(int argc, char *argv[])
{
	int	j;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	j = 0;
	while (argv[1][j])
	{
		print_and_upper(argv[1][j]);
		j++;
	}
	ft_putchar('\n');
	return (0);
}