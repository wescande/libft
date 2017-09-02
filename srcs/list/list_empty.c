/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:25:43 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:04:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_empty - tests whether a list is empty
** @head: the list to test.
*/

inline int		list_empty(const t_lx *head)
{
	return (READ_ONCE(head->next) == head);
}

/*
** list_empty_careful - tests whether a list is empty and not being modified
** @head: the list to test
**
** Description:
** tests whether a list is empty _and_ checks that no other CPU might be
** in the process of modifying either member (next or prev)
**
** NOTE: using list_empty_careful() without synchronization
** can only be safe if the only activity that can happen
** to the list entry is list_del_init(). Eg. it cannot be used
** if another CPU could re-list_add() it.
*/

inline int		list_empty_careful(const t_lx *head)
{
	t_lx *next;

	next = head->next;
	return ((next == head) && (next == head->prev));
}
