/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:17:20 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 01:21:54 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_del_init - deletes entry from list and reinitialize it.
** @elem: the element to delete from the list.
*/
inline void		list_del_init(t_lx *elem)
{
	list_del_only(elem->prev, elem->next);
	INIT_LIST_HEAD(elem); 
}