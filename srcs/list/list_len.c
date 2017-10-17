/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:43:54 by wescande          #+#    #+#             */
/*   Updated: 2017/10/17 16:45:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

inline size_t	list_len(t_lx *head)
{
	size_t	len;
	t_lx	*cursor;

	len = 0;
	cursor = head->next;
	while (cursor != head)
	{
		++len;
		cursor = cursor->next;
	}
	return (len);
}
