/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_findat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:59:46 by wescande          #+#    #+#             */
/*   Updated: 2017/10/20 17:45:06 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

inline t_lx		*list_findat(t_lx *head, size_t n)
{
	t_lx	*cursor;

	cursor = head->next;
	if (!n)
	{
		if (cursor == head)
			return (NULL);
		else
			return (cursor);
	}
	while (--n)
	{
		if (cursor == head)
			return (NULL);
		cursor = cursor->next;
	}
	if (cursor == head)
		return (NULL);
	return (cursor);
}
