/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 05:56:32 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/06 05:56:32 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_print_putnbr(nbr / 10);
	c = (nbr % 10) + 48;
	write(1, &c, 1);
}

int	main(void)
{
	int	n;

	n = 1;
	while (n <= 100)
	{
		if ((n % 3 == 0) && (n % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (n % 3 == 0)
			write(1, "fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_print_putnbr(n);
		write(1, "\n", 1);
		n++;
	}
	return (0);
}
