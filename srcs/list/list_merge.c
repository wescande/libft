/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:45:04 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:05:23 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

inline void		list_merge_only(t_lx *add, t_lx *head)
{
	t_lx *first;
	t_lx *last;
	t_lx *at;

	first = add->next;
	last = add->prev;
	at = head->next;
	first->prev = head;
	head->next = first;
	last->next = at;
	at->prev = last;
}

/*
** list_merge - join two lists
** @add: the new list to add.
** @head: the place to add it in the first list.
*/

inline void		list_merge(t_lx *add, t_lx *head)
{
	if (!list_empty(add))
		list_merge_only(add, head);
}

/*
** list_mergee_init - join two lists and reinitialise the emptied list.
** @add: the new list to add.
** @head: the place to add it in the first list.
**
** The list at @add is reinitialised
*/

inline void		list_merge_init(t_lx *add, t_lx *head)
{
	if (!list_empty(add))
	{
		list_merge_only(add, head);
		INIT_LIST_HEAD(add);
	}
}
