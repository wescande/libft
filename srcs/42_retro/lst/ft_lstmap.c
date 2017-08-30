/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 23:42:20 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 17:48:57 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l_new;
	t_list	*l_cur;

	l_new = NULL;
	if (lst && f)
	{
		l_new = f(lst);
		l_cur = l_new;
		while (lst->next)
		{
			l_cur->next = f(lst->next);
			l_cur = l_cur->next;
			lst = lst->next;
		}
	}
	return (l_new);
}
