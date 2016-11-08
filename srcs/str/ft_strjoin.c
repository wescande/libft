/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 01:06:00 by wescande          #+#    #+#             */
/*   Updated: 2016/11/03 17:45:54 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sptr;
	int		index;

	if (!s1 || !s2)
		return (NULL);
	if (!(sptr = (char*)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	index = 0;
	while (*s1)
	{
		sptr[index] = *s1;
		++s1;
		++index;
	}
	while (*s2)
	{
		sptr[index] = *s2;
		++s2;
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}
