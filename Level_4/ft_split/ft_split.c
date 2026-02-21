/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:38:46 by sarfreit          #+#    #+#             */
/*   Updated: 2026/02/21 22:38:46 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int is_space(char c)
{
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return (1);
    return (0);
}

int count_words(char *str)
{
    int i;
    int words;
    
    i = 0;
    words = 0;
    while (str[i])
    {
        while ((str[i]) && is_space(str[i]))
            i++;
        if ((str[i]) && !is_space(str[i]))
        {
            words++;
            while ((str[i]) && !is_space(str[i]))
                i++;
        }
    }
    return (words);
}

int  word_len(char *str, int i)
{
    int len;

    len = 0;
    while (str[i] && !is_space(str[i]))
    {
        len++;
        i++;
    }
    return (len);
}

char    **ft_split(char *str)
{
    int     i;
    char    **arr;
    int     w_len;
    int     start;
    int     k;

    arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
    if (!arr)
        return (NULL);
    i = 0;
    k = 0;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
        {
            w_len = word_len(str, i);
            arr[k] = (char *)malloc(sizeof(char) * (w_len + 1));
            if (!arr[k])
                return (NULL);
            start = 0;
            while (start < w_len)
            {
                arr[k][start] = str[start + i];
                start++;
            }
            arr[k][start] = '\0';
            i += w_len;
            k++;
        }
    }
    arr[k] = NULL;
    return (arr);
}
