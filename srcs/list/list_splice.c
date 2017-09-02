/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_splice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:31:49 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:05:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

static inline void	list_splice_only(const t_lx *list, t_lx *prev, t_lx *next)
{
	t_lx *first;
	t_lx *last;

	first = list->next;
	last = list->prev;
	first->prev = prev;
	prev->next = first;
	last->next = next;
	next->prev = last;
}

/*
** list_splice - join two lists, this is designed for stacks
** @list: the new list to add.
** @head: the place to add it in the first list.
*/

inline void			list_splice(const t_lx *list, t_lx *head)
{
	if (!list_empty(list))
		list_splice_only(list, head, head->next);
}

/*
** list_splice_tail - join two lists, each list being a queue
** @list: the new list to add.
** @head: the place to add it in the first list.
*/

inline void			list_splice_tail(t_lx *list, t_lx *head)
{
	if (!list_empty(list))
		list_splice_only(list, head->prev, head);
}

/*
** list_splice_init - join two lists and reinitialise the emptied list.
** @list: the new list to add.
** @head: the place to add it in the first list.
**
** The list at @list is reinitialised
*/

inline void			list_splice_init(t_lx *list, t_lx *head)
{
	if (!list_empty(list))
	{
		list_splice_only(list, head, head->next);
		INIT_LIST_HEAD(list);
	}
}

/*
** list_splice_tail_init - join two lists and reinitialise the emptied list
** @list: the new list to add.
** @head: the place to add it in the first list.
**
** Each of the lists is a queue.
** The list at @list is reinitialised
*/

inline void			list_splice_tail_init(t_lx *list, t_lx *head)
{
	if (!list_empty(list))
	{
		list_splice_only(list, head->prev, head);
		INIT_LIST_HEAD(list);
	}
}
