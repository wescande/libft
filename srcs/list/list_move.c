/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:18:53 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 01:19:35 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_move - delete from one list and add as another's head
** @elem: the entry to move
** @head: the head that will precede our entry
*/
inline void list_move(t_lx *elem, t_lx *head)
{
	list_del_only(elem->prev, elem->next);
	list_add(elem, head);
}