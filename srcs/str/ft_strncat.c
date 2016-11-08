/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 23:42:12 by wescande          #+#    #+#             */
/*   Updated: 2016/09/16 01:02:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ret;

	ret = dest;
	while (*ret)
		++ret;
	while (n && *src)
	{
		*ret = *src;
		++ret;
		++src;
		--n;
	}
	*ret = '\0';
	return (dest);
}
