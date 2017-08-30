/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:24:17 by wescande          #+#    #+#             */
/*   Updated: 2016/12/16 14:51:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*li_prev;
	t_list	*li_curr;
	int		is_sorting;

	is_sorting = true;
	while (is_sorting--)
	{
		li_prev = NULL;
		li_curr = *begin_list;
		while (li_curr && li_curr->next)
			if ((*cmp)(li_curr->content, li_curr->next->content) > 0)
			{
				(li_prev) ? li_prev->next = li_curr->next : 0;
				(!li_prev) ? *begin_list = li_curr->next : 0;
				li_prev = ft_lstswap(li_curr);
				is_sorting = true;
			}
			else
			{
				li_prev = li_curr;
				li_curr = li_curr->next;
			}
	}
}
