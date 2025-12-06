/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 08:53:11 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/06 08:53:11 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
#include <unistd.h>

int	main(void)
{
	char *str = "Hello";

	ft_putstr(str);

	return (0);
}
*/