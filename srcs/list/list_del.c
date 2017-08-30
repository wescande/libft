/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:41:05 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 01:21:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_del - deletes entry from list.
** @elem: the element to delete from the list.
** Note: list_empty on entry does not return true after this, the entry is in an undefined state.
*/
extern inline void		list_del(t_lx *elem)
{
	list_del_only(elem->prev, elem->next);
	elem->next = (void *)0;
	elem->prev = (void *)0;
}