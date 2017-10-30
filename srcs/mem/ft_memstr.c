/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:19:08 by wescande          #+#    #+#             */
/*   Updated: 2017/10/30 19:24:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memstr(const void *mem, const char *str, size_t n)
{
	size_t			len;

	len = ft_strlen(str);
	while (len <= n)
	{
		if (!ft_strncmp(mem, str, len))
			return ((void *)mem);
		++mem;
		--n;
	}
	return (NULL);
}
