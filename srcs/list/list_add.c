/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 10:06:45 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 00:23:31 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_add - add a new entry
** @new: new entry to be added
** @head: list head to add it after
**
** Insert a new entry after the specified head.
** This is good for implementing stacks.
*/
inline void list_add(t_lx *elem, t_lx *head)
{
	list_insert(elem, head, head->next);
}