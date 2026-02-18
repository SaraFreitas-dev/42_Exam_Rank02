<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:07:49 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/19 17:42:59 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;

	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

void ft_putnbr(int nbr)
{
	long 	n;
	char	c;

	n = (long)nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + 48;
	write(1, &c , 1);  
}

int	is_prime(int nbr)
{
	int	i;
	
	if (nbr <= 1)
		return (0);
	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	nbr;
	int	result;
	
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	result = 0;
	nbr = ft_atoi(argv[1]);
	if (nbr < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	while (nbr > 1)
	{
		if (is_prime(nbr) == 1)
			result += nbr;
		nbr--;
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 21:07:49 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/19 17:42:59 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;

	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

void ft_putnbr(int nbr)
{
	long 	n;
	char	c;

	n = (long)nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + 48;
	write(1, &c , 1);  
}

int	is_prime(int nbr)
{
	int	i;
	
	if (nbr <= 1)
		return (0);
	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	nbr;
	int	result;
	
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	else
	result = 0;
	nbr = ft_atoi(argv[1]);
	if (nbr < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	while (nbr > 1)
	{
		if (is_prime(nbr) == 1)
			result += nbr;
		nbr--;
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
>>>>>>> da77a03 (added max and prime)
