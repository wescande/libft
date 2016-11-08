/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 23:54:31 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 17:51:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j] && i + j < n - 1 && n > 0)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	if (n < i + j)
		return (n + ft_strlen(src));
	return (i + ft_strlen(src));
}
