/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:36:04 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 13:12:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		len;
	size_t		len_dest;

	if (!*needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	len_dest = ft_strlen(haystack);
	while (*haystack && len <= len_dest)
	{
		if (!ft_strncmp(haystack, needle, len))
			return ((char *)haystack);
		++haystack;
		--len_dest;
	}
	return (NULL);
}
