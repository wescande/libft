/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:17:34 by wescande          #+#    #+#             */
/*   Updated: 2016/11/23 13:05:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;
	char		c;

	if (!s)
		return (0);
	start = s;
	c = *s;
	++s;
	while (c != '\0')
	{
		c = *s;
		++s;
	}
	return (s - start - 1);
}
