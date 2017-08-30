/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:15:02 by wescande          #+#    #+#             */
/*   Updated: 2016/11/29 19:29:37 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstswap(t_list *l_cur)
{
	t_list	*l_next;

	l_next = l_cur;
	if (l_cur && l_cur->next)
	{
		l_next = l_cur->next;
		l_cur->next = l_next->next;
		l_next->next = l_cur;
	}
	return (l_next);
}
