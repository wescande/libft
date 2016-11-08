/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 23:19:59 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 14:43:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ret;

	ret = dest;
	while (n && *src)
	{
		*ret = *src;
		++ret;
		++src;
		--n;
	}
	while (n)
	{
		*ret = '\0';
		++ret;
		--n;
	}
	return (dest);
}
