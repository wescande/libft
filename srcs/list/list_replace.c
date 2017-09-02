/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_replace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:10:27 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:03:53 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_replace - replace old entry by new one
** @old : the element to be replaced
** @new : the new element to insert
**
** If @old was empty, it will be overwritten.
*/

inline void		list_replace(t_lx *old, t_lx *new)
{
	new->next = old->next;
	new->next->prev = new;
	new->prev = old->prev;
	new->prev->next = new;
}

inline void		list_replace_init(t_lx *old, t_lx *new)
{
	list_replace(old, new);
	INIT_LIST_HEAD(old);
}
