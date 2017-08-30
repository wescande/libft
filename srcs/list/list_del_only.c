/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:16:20 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 01:18:30 by wescande         ###   ########.fr       */
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
inline void list_del_only(t_lx *prev, t_lx *next)
{
	next->prev = prev;
	prev->next = next;
}