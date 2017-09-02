/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:41:05 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:04:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** Delete a list entry by making the prev/next entries
** point to each other.
**
** This is only for internal list manipulation where we know
** the prev/next entries already!
*/

inline void		list_del_only(t_lx *prev, t_lx *next)
{
	next->prev = prev;
	WRITE_ONCE(prev->next, next);
}

/*
** list_del - deletes entry from list.
** @elem: the element to delete from the list.
** Note: list_empty on entry does not return true after this,
** the entry is in an undefined state.
*/

inline void		list_del(t_lx *elem)
{
	list_del_only(elem->prev, elem->next);
	elem->next = NULL;
	elem->prev = NULL;
}

/*
** list_del_init - deletes entry from list and reinitialize it.
** @elem: the element to delete from the list.
*/

inline void		list_del_init(t_lx *elem)
{
	list_del_only(elem->prev, elem->next);
	INIT_LIST_HEAD(elem);
}
