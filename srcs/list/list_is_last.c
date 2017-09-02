/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_is_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:16:57 by wescande          #+#    #+#             */
/*   Updated: 2017/09/02 16:02:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

/*
** list_is_last - tests whether @list is the last entry in list @head
** @list: the entry to test
** @head: the head of the list
*/

inline int		list_is_last(const t_lx *list, t_lx *head)
{
	return (list->next == head);
}
