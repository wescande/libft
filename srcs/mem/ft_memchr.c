/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 18:52:50 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 14:17:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sptr;
	unsigned char cptr;

	sptr = (unsigned char*)s;
	cptr = (unsigned char)c;
	while (n--)
	{
		if (*sptr == cptr)
			return (sptr);
		++sptr;
	}
	return (NULL);
}
