/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:13:05 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 00:23:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

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