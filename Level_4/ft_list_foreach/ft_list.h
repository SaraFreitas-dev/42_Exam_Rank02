/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:23:44 by sarfreit          #+#    #+#             */
/*   Updated: 2026/02/21 23:23:44 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST
# define FT_LIST

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

#endif