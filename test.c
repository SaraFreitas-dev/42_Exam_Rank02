/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:08:23 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/20 17:27:13 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_atoi_base("-1011", 2));
	printf("%d\n", ft_atoi_base("1011", 2));
	printf("%d\n", ft_atoi_base("1A", 16));
	printf("%d\n", ft_atoi_base("7F", 16));

    return (0);
}

/*
“Multiplico pelo tamanho da base e somo o valor do símbolo.”
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/