/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:36:04 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 13:12:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_little;
	size_t	l_big;

	if (!*little)
		return ((char *)big);
	l_little = ft_strlen(little);
	l_big = ft_strlen(big);
	while (*big && len >= l_little && l_little <= l_big)
	{
		if (!ft_strncmp(big, little, l_little))
			return ((char *)big);
		--len;
		--l_big;
		++big;
	}
	return (NULL);
}
