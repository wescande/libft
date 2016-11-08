/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 23:21:11 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 13:48:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l_nx;

	if (alst && del)
	{
		while (*alst)
		{
			l_nx = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = l_nx;
		}
		*alst = NULL;
	}
}
