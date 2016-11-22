/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:14:39 by wescande          #+#    #+#             */
/*   Updated: 2016/11/22 12:22:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoinf(void *mem1, void *mem2, size_t len1, size_t len2)
{
	void	*ret;

	ret = ft_memjoin(mem1, mem2, len1, len2);
	ft_memdel(&mem1);
	ft_memdel(&mem2);
	return (ret);
}
