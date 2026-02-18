/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:54:28 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/17 21:54:28 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 0;
	bit = 0;
	while (i <= 7)
	{
		if (octet & (1 << i))
			bit = bit | (1 << (7 - i));
		i++;
	}
	return (bit);
}