/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:14:39 by wescande          #+#    #+#             */
/*   Updated: 2016/11/22 16:44:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *mem1, const void *mem2,
					size_t len1, size_t len2)
{
	void	*ret;

	if (!(ret = (void *)malloc(sizeof(void) * (len1 + len2))))
		return (NULL);
	ft_memcpy(ret, mem1, len1);
	ft_memcpy(ret + len1, mem2, len2);
	return (ret);
}
