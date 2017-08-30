/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_merge_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:28:26 by wescande          #+#    #+#             */
/*   Updated: 2017/08/31 00:33:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

inline void		list_merge_only(t_lx *add, t_lx *head)
{
	t_lx *first;
	t_lx *last;
	t_lx *at;

	first = add->next;
	last = add->prev;
	at = head->next;
	first->prev = head;
	head->next = first;
	last->next = at;
	at->prev = last;
}