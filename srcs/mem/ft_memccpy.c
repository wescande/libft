/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:23:37 by wescande          #+#    #+#             */
/*   Updated: 2016/11/02 14:33:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*cptr1;
	const char	*cptr2;

	cptr1 = (char*)dest;
	cptr2 = (char*)src;
	while (n--)
	{
		*(cptr1++) = *cptr2;
		if (*(cptr2++) == (char)c)
			return (cptr1);
	}
	return (NULL);
}
