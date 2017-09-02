/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cut_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:24:08 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:04:51 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

static inline void	list_cut_position_only(t_lx *list, t_lx *head, t_lx *entry)
{
	t_lx	*new_first;

	new_first = entry->next;
	list->next = head->next;
	list->next->prev = list;
	list->prev = entry;
	entry->next = list;
	head->next = new_first;
	new_first->prev = head;
}

/*
** list_cut_position - cut a list into two
** @list: a new list to add all removed entries
** @head: a list with entries
** @entry: an entry within head, could be the head itself
** and if so we won't cut the list
**
** This helper moves the initial part of @head, up to and
** including @entry, from @head to @list. You should
** pass on @entry an element you know is on @head. @list
** should be an empty list or a list you do not care about
** losing its data.
*/

inline void			list_cut_position(t_lx *list, t_lx *head, t_lx *entry)
{
	if (list_empty(head))
		return ;
	if (list_is_singular(head) &&
		(head->next != entry && head != entry))
		return ;
	if (entry == head)
		INIT_LIST_HEAD(list);
	else
		list_cut_position_only(list, head, entry);
}
