/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:45:01 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/10 14:45:01 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

/*
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("%d \n%d \n%d \n%d", atoi("-10"), atoi("  30"), atoi("+20"), atoi("+--10"));
	printf("\n MY ATOI \n");
	printf("%d \n%d \n%d \n%d", ft_atoi("-10"), ft_atoi("  30"), ft_atoi("+20"), ft_atoi("+--10"));
}
*/