/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:21:34 by wescande          #+#    #+#             */
/*   Updated: 2017/11/05 15:01:56 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

#ifdef FULL_LIBFT

/*
** list_rotate_left - rotate the list to the left
** @head: the head of the list
*/

inline void		list_rotate_left(t_lx *head)
{
	t_lx	*first;

	if (!list_empty(head))
	{
		first = head->next;
		list_move_tail(first, head);
	}
}

#endif
