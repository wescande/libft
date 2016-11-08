/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:36:04 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 16:13:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_little;

	if (!*little)
		return ((char *)big);
	l_little = ft_strlen(little);
	while (*big && len >= l_little)
	{
		if (!ft_strncmp(big, little, l_little))
			return ((char *)big);
		--len;
		++big;
	}
	return (NULL);
}
