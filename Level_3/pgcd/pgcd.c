/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:31:17 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/21 17:31:17 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	pgcd(char *str1, char *str2)
{
	int	num1;
	int	num2;
	int	current_div;
	int	max_div;

	num1 = atoi(str1);
	num2 = atoi(str2);
	current_div = 1;
	max_div = 0;
	while ((current_div <= num1) && (current_div <= num2))
	{
		if ((num1 % current_div == 0) && (num2 % current_div == 0))
			max_div = current_div;
		current_div++;
	}
	return (max_div);
}

int	main(int argc, char *argv[])
{
	int	num;
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	num = pgcd(argv[1], argv[2]);
	printf("%d\n", num);
	return (0);
}