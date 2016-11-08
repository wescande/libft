/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:36:04 by wescande          #+#    #+#             */
/*   Updated: 2016/09/25 23:06:30 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		len;

	if (!*needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, len))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
