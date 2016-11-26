/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:42:19 by wescande          #+#    #+#             */
/*   Updated: 2016/11/25 21:02:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreverse(t_list **lst)
{
	t_list	*l_prev;
	t_list	*l_cur;
	t_list	*l_next;

	l_prev = NULL;
	if (lst)
	{
		l_cur = *lst;
		while (l_cur)
		{
			l_next = l_cur->next;
			l_cur->next = l_prev;
			l_prev = l_cur;
			l_cur = l_next;
		}
		*lst = l_prev;
	}
	return (l_prev);
}
