/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:27:24 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 17:29:35 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_space(char c)
{
    if ((c == 32) || ((c >= 9) && (c <= 13)))
        return (1);
    return (0);
}

int is_valid_base(char c, int base_len)
{
    char    *lc_base;
    char    *uc_base;
    int     i;

    lc_base = "0123456789abcdef";
    uc_base = "0123456789ABCDEF";
    i = 0;
    while (i < base_len)
    {
        if ((c == lc_base[i] || (c == uc_base[i])))
            return (i);
        i++;
    }
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int     i;
    int     sign;
    int     result;

    i = 0;
    sign = 1;
    result = 0;
    while (is_space(str[i]))
        i++;
    if ((str[i] == '-') || (str[i] == '+'))
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] && (is_valid_base(str[i], str_base) != -1))
    {
        result = result * str_base + is_valid_base(str[i], str_base);
        i++;
    }
    return (result * sign);
}

/*
#include <stdio.h>
// While it's a valid value (str[i]) - Multiply by the base length and add the value of the symbol (i).

int main(void)
{
    printf("%d\n", ft_atoi_base("-1011", 2));
	printf("%d\n", ft_atoi_base("1011", 2));
	printf("%d\n", ft_atoi_base("1A", 16));
	printf("%d\n", ft_atoi_base("7F", 16));

    return (0);
}
*/