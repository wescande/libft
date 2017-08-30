/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:08:36 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 00:23:51 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** Insert a new entry between two known consecutive entries. 
**
** This is only for internal list manipulation where we know
** the prev/next entries already!
*/
inline void list_insert(t_lx *new, t_lx *prev, t_lx *next)
{
	new->next = next;
	new->prev = prev;
	next->prev = new;
	prev->next = new;
}