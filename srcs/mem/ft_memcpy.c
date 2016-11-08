/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 22:06:37 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 16:15:50 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long	*lptr1;
	long	*lptr2;
	char	*cptr1;
	char	*cptr2;

	lptr1 = (long*)dest;
	lptr2 = (long*)src;
	while (n >= sizeof(long))
	{
		*(lptr1++) = *(lptr2++);
		n -= sizeof(long);
	}
	cptr1 = (char*)lptr1;
	cptr2 = (char*)lptr2;
	while (n--)
		*(cptr1++) = *(cptr2++);
	return (dest);
}
