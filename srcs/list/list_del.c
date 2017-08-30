/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 13:41:05 by wescande          #+#    #+#             */
/*   Updated: 2017/08/30 13:43:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void list_del(t_lx *elem)
{
	elem->next->prev = elem->prev;
	elem->prev->next = elem->next;
	new_item->next = head->next;
	new_item->prev = head;
	head->next->prev = new_item;
	atomic_write_barrier();
	head->next = new_item;
}