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
	return ((octet << 4) | (octet >> 4));
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