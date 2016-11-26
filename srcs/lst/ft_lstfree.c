/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:27:18 by wescande          #+#    #+#             */
/*   Updated: 2016/11/25 20:49:40 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **alst)
{
	t_list	*l_nx;

	if (alst)
	{
		while (*alst)
		{
			l_nx = (*alst)->next;
			free((*alst)->content);
			(*alst)->content = NULL;
			free(*alst);
			*alst = l_nx;
		}
		*alst = NULL;
	}
}
