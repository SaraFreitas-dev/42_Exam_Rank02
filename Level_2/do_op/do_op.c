/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:26:52 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/10 14:26:52 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int nbr1;
	int	nbr2;
	int result;

	if (argc != 4)
	{
		printf("\n");
		return (0);
	}
	nbr1 = atoi(argv[1]);
	nbr2 = atoi(argv[3]);
	result = 0;
	if (argv[2][0] == '+')
		result = nbr1 + nbr2;
	else if (argv[2][0] == '-')
		result = nbr1 - nbr2;
	else if (argv[2][0] == '*')
		result = nbr1 * nbr2;
	else if (argv[2][0] == '/')
		result = nbr1 / nbr2;
	else if (argv[2][0] == '%')
		result = nbr1 % nbr2;
	printf("%d\n", result);
	return (0);
}