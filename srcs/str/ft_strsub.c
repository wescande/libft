/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:51:05 by wescande          #+#    #+#             */
/*   Updated: 2016/11/15 18:00:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sptr;
	int		index;

	if (!s)
		return (NULL);
	if (!(sptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	while (len - index)
	{
		sptr[index] = s[start + index];
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}
