/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 10:06:45 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:02:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** Insert a new entry between two known consecutive entries.
**
** This is only for internal list manipulation where we know
** the prev/next entries already!
*/

inline void		list_insert(t_lx *new, t_lx *prev, t_lx *next)
{
	new->next = next;
	new->prev = prev;
	next->prev = new;
	WRITE_ONCE(prev->next, new);
}

/*
** list_add - add a new entry
** @new: new entry to be added
** @head: list head to add it after
**
** Insert a new entry after the specified head.
** This is good for implementing stacks.
*/

inline void		list_add(t_lx *elem, t_lx *head)
{
	list_insert(elem, head, head->next);
}

/*
** list_add_tail - add a new entry
** @new: new entry to be added
** @head: list head to add it before
**
** Insert a new entry before the specified head.
** This is useful for implementing queues.
*/

inline void		list_add_tail(t_lx *new, t_lx *head)
{
	list_insert(new, head->prev, head);
}
