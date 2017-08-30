/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:17:34 by wescande          #+#    #+#             */
/*   Updated: 2016/12/01 18:40:52 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ld_new(t_ld **alst, void *content)
{
	t_ld	*new;

	if ((new = (t_ld *)malloc(sizeof(t_ld))))
	{
		new->content = content;
		new->prev = NULL;
		new->next = NULL;
		*alst = new;
	}
}
