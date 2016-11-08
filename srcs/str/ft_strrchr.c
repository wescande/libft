/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 20:19:44 by wescande          #+#    #+#             */
/*   Updated: 2016/09/16 20:34:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	cch = (char)c;
	char		*s_ret;

	s_ret = NULL;
	while (*s)
	{
		if (*s == cch)
			s_ret = (char*)s;
		++s;
	}
	if (*s == cch)
		return ((char*)s);
	return (s_ret);
}
