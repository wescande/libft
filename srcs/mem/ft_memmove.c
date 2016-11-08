/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 23:11:38 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 16:57:35 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i--)
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
	}
	return (dest);
}
