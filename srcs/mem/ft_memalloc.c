/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 23:26:30 by wescande          #+#    #+#             */
/*   Updated: 2016/09/17 23:32:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*vptr;

	if (!(vptr = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(vptr, size);
	return (vptr);
}
