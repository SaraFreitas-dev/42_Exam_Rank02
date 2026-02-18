/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:53:52 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/17 21:53:52 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
int	main(void)
{
	print_bits(2);
}
*/
