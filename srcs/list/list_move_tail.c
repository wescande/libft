/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:24:10 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 00:25:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_move_tail - delete from one list and add as another's tail
** @elem: the entry to move
** @head: the head that will follow our entry
*/
inline void list_move_tail(t_lx *elem, t_lx *head)
{
	list_del_only(elem->prev, elem->next);
	list_add_tail(elem, head);
}