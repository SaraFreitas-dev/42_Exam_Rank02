/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:50:00 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/15 21:50:00 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	    is_power_of_2(unsigned int n)
{
	if (n == 1)
		return (1);
	if ((n < 1) || (n % 2 != 0))
		return (0);
	return(is_power_of_2(n / 2));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("Result is: %d\n", is_power_of_2(8));
}
*/

