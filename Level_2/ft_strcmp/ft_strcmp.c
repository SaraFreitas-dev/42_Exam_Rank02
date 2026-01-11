/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:43:37 by sarfreit          #+#    #+#             */
/*   Updated: 2026/01/10 20:43:37 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] -s2[i]);
}


/*
man strcmp(): 
Returns an integer indicating the result of the comparison, as  fol‐
       lows:
       •  0, if the s1 and s2 are equal;
       •  a negative value if s1 is less than s2;
       •  a positive value if s1 is greater than s2.

	   $ ./string_comp ABC ABC
           <str1> and <str2> are equal
           $ ./string_comp ABC AB      # 'C' is ASCII 67; 'C' - '\0' = 67
           <str1> is greater than <str2> (67)
           $ ./string_comp ABA ABZ     # 'A' is ASCII 65; 'Z' is ASCII 90
           <str1> is less than <str2> (-25)
           $ ./string_comp ABJ ABC
           <str1> is greater than <str2> (7)
           $ ./string_comp $'\201' A   # 0201 - 0101 = 0100 (or 64 decimal)
           <str1> is greater than <str2> (64)
*/