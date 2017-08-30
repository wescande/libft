/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:35:48 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 00:36:54 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_mergee_init - join two lists and reinitialise the emptied list.
** @add: the new list to add.
** @head: the place to add it in the first list.
**
** The list at @add is reinitialised
 */
 static inline void list_merge_init(t_lx *add, t_lx *head)
{
	if (!list_empty(add))
	{
		list_merge_only(add, head);
		INIT_LIST_HEAD(add);
	}
}