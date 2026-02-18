/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 23:04:22 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/17 23:04:22 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 0;
	bit = 0;
	while (i < 4)
	{
		if (octet & (1 << i))
			bit = bit | (1 << (4 + i));
		i++;
	}
	while (i <= 7)
	{
		if (octet & (1 << i))
			bit = bit | (1 << (i - 4));
		i++;
	}
	return (bit);
}

/*
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			bit = '1';
		else
			bit = '0';
		write (1, &bit, 1);
		i--;
	}

}

int	main(void)
{
	print_bits(1);
	write(1, "\n", 1);
	unsigned char	swap = swap_bits(1);
	print_bits(swap);

	return (0);
}
*/