/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_is_singular.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:22:57 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:02:32 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_is_singular - tests whether a list has just one entry.
** @head: the list to test.
*/

inline int		list_is_singular(const t_lx *head)
{
	return (!list_empty(head) && (head->next == head->prev));
}
