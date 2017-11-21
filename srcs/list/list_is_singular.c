/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_is_singular.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:22:57 by wescande          #+#    #+#             */
/*   Updated: 2017/11/21 12:23:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

#ifdef FULL_LIBFT

/*
** list_is_singular - tests whether a list has just one entry.
** @head: the list to test.
*/

inline int		list_is_singular(const t_lx *head)
{
	return (!list_empty(head) && (head->next == head->prev));
}
#endif
