/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:29:55 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 14:11:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*str1 = (const unsigned char *)s1;
	const unsigned char	*str2 = (const unsigned char *)s2;
	unsigned char		c1;
	unsigned char		c2;

	if (!s1 || !s2)
		return (1);
	c1 = (unsigned char)*str1++;
	c2 = (unsigned char)*str2++;
	if (!c1)
		return (c1 - c2);
	while (c1 == c2)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (!c1)
			return (c1 - c2);
	}
	return (c1 - c2);
}
